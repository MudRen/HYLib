
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
����������ʯ·����������˺��١�����Ҳû��ʲô������Ե�
��Щ���塣���߲�ʱ�������ֵ�������ֻ���������ϰ���Ӵ��������
�߹�����ʱ��ͷ�������㼸�ۡ�
LONG);

  set("exits", ([ 

  "north":__DIR__"xijie1",
  "south":__DIR__"suishilu2",
       ]));
 
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}

