// Room: /d/yandang/luoyan19.c

inherit ROOM;

void create ()
{
  set ("short", "Ů���Ӿ���");
  set ("long", @LONG
Ů���Ӿ����бȽϸɾ�,�Ͼ�Ů���ӻ��Ǻܰ������,��ǰ����ױ̨
�ϳ��˵���Ǿ���,�������в�������֬��,һ���������Ļ�ƿ��
���ż�֧�ʻ�.
LONG);

  set("sleep_equipment", "ľ��");
  set("sleep_room", "1");
  set("no_fight", "1");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"luoyan17",
  "south" : __DIR__"luoyan22",
]));

  setup();
}
void init()
{
	add_action("do_qu", "qu");
}

int do_qu(string arg)
{
    object me,ob1;
    me=this_player();

    if ( (arg!="flower")&&(arg!="��")) return 0;
    message_vision(
"$N�ӻ�ƿ��ȡ��һ֦����\n", me);
      		 ob1=clone_object(__DIR__"obj/hongmeigui.c");
			 ob1->move(me);
        return 1;
}
