inherit ROOM;
#include <ansi.h>

int do_install(string arg);

void create ()
{
  set ("short","��԰");
  set ("long", @LONG
�����ǾŽ��Ĵ�԰�������������˺ܶ࣬���ֵ����������ڶ�����
�߻���һ����¥����ǰ�����ϡ�����¥����������Ĵ�����������ҫ��
�������⡣¥�ϴ����˺Ⱦơ���Ц��������������ָ���԰������һ��
���֡�
LONG);

  set("exits", ([ 

  "up":__DIR__"chunzailou",
  "west":__DIR__"beidajie2",
         ]));
set("outdoors","jiujiang");
  set("valid_startroom", 1);
  set("cisha_job",1);
  setup();
 
}

