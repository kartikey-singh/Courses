function p = predict(Theta1, Theta2, X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)

% Useful values
m = size(X, 1);
num_labels = size(Theta2, 1);

% You need to return the following variable(p) correctly 
p = zeros(size(X, 1), 1);
X = [ones(m, 1) X];
% ====================== YOUR CODE HERE ======================
% Instructions: Complete the following code to make predictions using
%               your learned neural network. You should set p to a 
%               vector containing labels between 1 to num_labels.
%
% Hint: The max function might come in useful. In particular, the max
%       function can also return the index of the max element, for more
%       information see 'help max'. If your examples are in rows, then, you
%       can use max(A, [], 2) to obtain the max for each row.
%
% Here we have X = 5000x401 Theta1 25x401 Theta2 10x26 X1 = 5000x26 X2=5000x10
% currently why we have 25 activation units in layer one unknown and how theta's
% are calculated ?
  X1 = sigmoid(X*Theta1');
  m1 = size(X1, 1);
  X1 = [ones(m, 1) X1];
% similar to explanation of predictOneVsAll.m  
  X2 = sigmoid(X1*Theta2');  
  [maxPerColumn,p] = max(X2,[],2);
% =========================================================================


end
