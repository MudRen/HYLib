
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����Ƕ���֡�������һ�Ҷĳ���������һ�ҿ�ջ���ĳ��к��е�
����ԶԶ�Ĵ��˹�������ʱ�ж�ͽ�����洹��ͷ���˳�����Ҳ�ж�ͽ��
�˴Ӷĳ��ù������˳������ϱ���һ�ҿ�ջ����С�������ſ��������
���ſ��ˡ�
LONG);

  set("exits", ([ 

 "east":__DIR__"dongdajie3",
  "west":__DIR__"dongdajie1",
  "north":__DIR__"duchang",
  "south":__DIR__"kezhan",
         ]));
          set("objects", ([
              "/clone/misc/dache" : 1,
        ]) );
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}

