// Room: /d/hainan/pubu
inherit ROOM;
void create()
{
  set ("short", "�ٲ�");
  set ("long", @LONG
�ٲ�����һ�������������,��������µ�һ����Ԩ,����¡����
����,������µ�������÷���.˿˿ˮ�����紵��,Ʈ����������,Զ
����ɽ����÷�����������!
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"road5",
  "west" : __DIR__"road4",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "�ٲ�" : "����ϸ�۲��ٲ�,�ƺ��������淢��Щʲô,��ˮ��̫��,��ʵ��
�������.
",
]));
  set("outdoors", "/d/hainan");
  setup();
}
void init()
{
   add_action("do_jump","jump");
}
int do_jump(string str)
{
    if (str!="�ٲ�"&&str!="pubu")  return 0;
message_vision("$N����һ�������ٲ���ȥ!\n",this_player());
tell_room("/d/hainan/pubuhou",this_player()->query("name")+"��������˽���!\n");
this_player()->move("/d/hainan/pubuhou");
tell_object(this_player(),"������ٲ�,���±�һ�������ĺ�ɫ��������һ��!\n");
return 1;
}
