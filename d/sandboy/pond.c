// Room: /d/sandboy/pond 
inherit ROOM; 
 
void create ()
{
  set ("short", "С����");
  set ("long", @LONG
����ɫ�ĸ�Ƽ�����ˮ����,�������ĵط�,һ����ˮ��������������
��,������һ���޼ʵĽ�ɫ��Ұ,�����﹡�������,����ȥ��һƬ����ݵ�.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/watercart.c" : 1,
]));
set("outdoors","/d/jiangnan");
  set("item_desc", ([ /* sizeof() == 1 */
  "ˮ��" : "�ý�̤��ʱ,�ܰ�ˮ�ӳ����г�ȡ��ˮ����.
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road1",
  "west" : __DIR__"turf",
]));

  setup();
}
void init()
{
   add_action("do_jump","jump");
}
int do_jump(string arg)
{
  object player;
  player=this_player();
if (!arg||(arg!="����"&&arg!="down")) return 0;
if (living(player)&&environment(player)==this_object())
      {
         write(player->name()+"��ͨһ���������,�����ϸ�ˮ��.\n");
         tell_room(__DIR__"inpond","������ͬһ���ʯ������ˮ��.\n");
         player->move(__DIR__"inpond");
        return 1;
       }
 return 0;
}
