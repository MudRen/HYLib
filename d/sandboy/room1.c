// Room: /d/sandboy/room1 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "����");
  set ("long", @LONG
���汱ǽ��һ���ƾɵĳ�̨,����һֻȱ�˿ڵ������з��˼�����ͷ,��
��һֻ����¯�л�������������,������ǽ���·��˼�������.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2",
  "south" : __DIR__"yuanzi",
]));
  setup();
}
