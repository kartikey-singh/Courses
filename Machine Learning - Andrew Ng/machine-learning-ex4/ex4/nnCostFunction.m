function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%NNCOSTFUNCTION Implements the neural network cost function for a two layer
%neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices. 
% 
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%

% Reshape nn_params back into the parameters Theta1 and Theta2, the weight matrices
% for our 2 layer neural network
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));

% ====================== YOUR CODE HERE ======================
% Instructions: You should complete the code by working through the
%               following parts.
%
% Part 1: Feedforward the neural network and return the cost in the
%         variable J. After implementing Part 1, you can verify that your
%         cost function computation is correct by verifying the cost
%         computed in ex4.m
%
% Part 2: Implement the backpropagation algorithm to compute the gradients
%         Theta1_grad and Theta2_grad. You should return the partial derivatives of
%         the cost function with respect to Theta1 and Theta2 in Theta1_grad and
%         Theta2_grad, respectively. After implementing Part 2, you can check
%         that your implementation is correct by running checkNNGradients
%
%         Note: The vector y passed into the function is a vector of labels
%               containing values from 1..K. You need to map this vector into a 
%               binary vector of 1's and 0's to be used with the neural network
%               cost function.
%
%         Hint: We recommend implementing backpropagation using a for-loop
%               over the training examples if you are implementing it for the 
%               first time.
%
% Part 3: Implement regularization with the cost function and gradients.
%
%         Hint: You can implement this around the code for
%               backpropagation. That is, you can compute the gradients for
%               the regularization separately and then add them to Theta1_grad
%               and Theta2_grad from Part 2.
%

  % Here we have X1=5000x401 Theta1=25x401 X2=5000x26 Theta2=10x26 X3=5000x10
  X1 = [ones(m,1) X];
  Z2 = X1*Theta1';
  X2 = sigmoid(Z2);
  m1 = size(X1, 1);
  X2 = [ones(m1, 1) X2];
  Z3 = X2*Theta2';
  X3 = sigmoid(Z3); 
  H = X3;
  Y = zeros(m,num_labels);
  % The below code is done so as to make it like if y=3 then y=[0 0 1 .. 0]
  % As cost function only works on Y = 1/0 type vectors like the above one.
  for i = 1:m,
    Y(i,y(i)) = 1;
  end;  
  % Unregularized Cost function.
  J = -(1/m)*sum(sum(Y.*log(H) + (1 - Y).*log(1 - H)));
  % Regularization Parameter we do not take a[i,j] j = 0 column during regularization
  reg = (lambda/(2*m))*(sum(sum(Theta1(:,2:end).^2)) + sum(sum(Theta2(:,2:end).^2)));
  J = J + reg;  
  % BackPropagation
  % delta3=5000x10 delta2=5000x25 after removing d0
  delta3 = X3 - Y; 
  delta2 = (delta3*Theta2)(:,2:end).*(sigmoidGradient(Z2)); %discard first row as it of bias units so 5000x25
  D2 = (1/m)*(delta3'*X2); % D2= 10x26
  D1 = (1/m)*(delta2'*X1); % D1= 25x401
  Theta2_grad = D2;
  Theta1_grad = D1;
  Theta2_grad(:,2:end) = Theta2_grad(:,2:end) + (lambda/m)*Theta2(:,2:end);
  Theta1_grad(:,2:end) = Theta1_grad(:,2:end) + (lambda/m)*Theta1(:,2:end);
  
% -------------------------------------------------------------
% =========================================================================
% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];

end
