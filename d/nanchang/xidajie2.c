
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�������ϲ�������֡����߾����ϲ�������ʤ��۶�����Ķ����ˡ���
����һ����ͤ���кܶ����������̸Ц������������۶���������ľ�ɫ��
�ϱ���һ�ұ����꣬���洫����ƹ���ô��������������������˺ܶ࣬
���ַǷ���
LONG);

  set("exits", ([ 
 "north":__DIR__"liangting",
  "west":__DIR__"dongan1",
  "east":__DIR__"xidajie1",
  "south":__DIR__"bingqidian",
         ]));
  set("objects",([
    "/clone/npc/man":1,
    ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}

