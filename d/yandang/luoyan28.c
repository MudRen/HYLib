// Room: /d/yandang/luoyan28.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������С����鷿,Ҳ����ƽ��ɢ�ĵĵط�,��˵������ʦ����Ȼ,
�Ѵ������,���˲�������ĵز�.�ıڰ��������,���������µ�����
(table)��,����һЩ��īʲô��,�Ա���һ�Ź���,ɫ����,ȴ��������
��Ӱ��.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/table.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"luoyan27",
  "north" : __DIR__"luoyan30",
]));

	setup();
}
void init()
{
        add_action("do_get", "get");
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
        	item = new(__DIR__"obj/hubi");
        	item->move(con);
        	item = new(__DIR__"obj/duanyan");
        	item->move(con);
        	item = new(__DIR__"obj/songmo");
        	item->move(con);
        }
}

int do_get(string arg)
{
	string 		obj, from;
	object		me, table, target, taro;

	if(sscanf(arg, "%s from %s", obj, from)==2 ) {
		if(obj == "all") {
			write("һ����̫�ණ����̫���ԡ�\n");
			return 1;
		}
		table =  present("table",this_object());
		target =  present(from,this_object());
		me = this_player();
		if(target == table) {
			taro =  present(obj, target);
			if(taro && random(10) > 4) {
				message_vision("$N���濴�˿�,û��,������������Щ������������\n", me);
			}
		}
	}
	return 0;
}