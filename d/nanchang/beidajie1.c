
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�������ϲ��ı���֡�����������Ѿ��ܶ��ˣ������������ò���
�֡��Ա���һ��С�Եֻ꣬����С����������������к������Ŀ��ˣ�
һ��������Ǳ�Ʈ������ʱҲ���������ȾƳ��ֵ�������
LONG);

  set("exits", ([ 

  "south":__DIR__"beidajie2",
  "west":__DIR__"xiaochidian",
  "north":__DIR__"beimen",
         ]));
  set("objects",([
    "/clone/npc/man":1,
    ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

