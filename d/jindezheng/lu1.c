// Room: /d/jindezheng/lu1
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG
һƬ������,�������˺��һ����Ҷ.��һ��С����Լ��������,ǰ
���ƺ�������һ������.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"lu2",
  "northeast" : __DIR__"shulin2",
]));
  set("outdoors", "/d/jindezheng");
  setup();
//  replace_program(ROOM);
}
void init()
{
        add_action("do_go","go");

}

int do_go()
{
if(random(3)){
this_player()->move(this_object());
return 1;
}
}
