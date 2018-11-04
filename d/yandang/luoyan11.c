// Room: /d/yandang/luoyan11.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG
�˴�������ɽׯ�ĳ���,�м���������æ���Ȼ���,���ڴ���ð��
���ܵĻ��,�Աߵ�����(table)���Ѱ����˼�����,������ζ������,������
�����ܴ󱥿ڸ���.
LONG);

  set("no_fight", "1");
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"luoyan8",
]));
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"obj/pot.c" : 1,
  __DIR__"obj/table.c" : 1,
  __DIR__"npc/chushi.c" : 1,
]));

  setup();
}
void reset()
{
        object 		*inv;
        object 		con, item;
	int		i;	

        ::reset();
        con = present("table", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 3) {
	        for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
        	item = new(__DIR__"obj/food1");
        	item->move(con);
        	item = new(__DIR__"obj/food1");
        	item->move(con);
        	item = new(__DIR__"obj/food1");
        	item->move(con);
        	item = new(__DIR__"obj/food2");
        	item->move(con);
        	item = new(__DIR__"obj/food2");
        	item->move(con);
        	item = new(__DIR__"obj/food2");
        	item->move(con);

        }
}
int valid_leave(object me, string dir)
{
  if(dir!="east") return ::valid_leave(me, dir);

  if(present("food", me))
    return notify_fail("�����Ӻٺ�һЦ,���ִ����������:�������ֳ��ִ�!\n");
  else
    return ::valid_leave(me, dir);
}

