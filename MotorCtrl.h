class MotorCtrl {
 private:
  int IN1, IN2;
  static int inst_num;

 public:
  MotorCtrl(int I1, int I2);
  void move(int speed);
  void brake(int time);
};