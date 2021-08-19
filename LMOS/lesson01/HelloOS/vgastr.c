void _strwrite(char *string)
{
  // 内存空间里 0xb8000 这个位置便是显卡VESA标准的起始地址
  // 屏幕分为 80 * 24 个像素单位，把 0xb8000 开始的字节映射到对应单位中，两个字节代表一个字符
  // 第一个字节是ascii编码，第二个字节是颜色值
  char *p_strdst = (char *)0xb8000;

  // C语言中字符串以 ascii 码 '\0' 为结束符，其int值也就是 0
  while (*string)
  {
    *p_strdst = *string;
    string++;
    // 跳过颜色值，直接赋ascii值
    p_strdst += 2;
  }
}

// ...支持多个参数，类似于Java，为了满足stdio.h里printf的使用规范
void printf(char *fmt, ...)
{
  _strwrite(fmt);
  return;
}