// Room: /d/sandboy/undertree 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "��������");
  set ("long", @LONG
�ߴ������֦Ҷ��ï,�����֦��������,����������֮��,�̸�����.
������һƬɹ�ȳ�,���п�ˮ��.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"well",
  "west" : __DIR__"ground",
]));
set("outdoors","/d/jiangnan");
  setup();
}
void init()
{
  add_action("do_climb","climb");
}
int do_climb(string arg)
{
  object pla;
  pla=this_player();
if (!arg||arg!="����") return 
       notify_fail("��Ҫ��ʲô?\n");
if (living(pla)&&environment(pla)==this_object())
   message_vision("$N˫����������,����������ȥ.\n",pla);
tell_room(__DIR__"intree","������������.\n");
  pla->move(__DIR__"intree");
return 1;
}
