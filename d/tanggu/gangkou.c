#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������Ǵ�֮�����˻��Ĵ��Ž�ʯ����������������������һȺȺ��Ÿ
��ŷŷ..���ؽ��ţ���ʱ�����Ծ�����棬��������˻����������Ҵ󴬣�
�������ż����������ˣ��˴��ɶɹ��󺣵��ﺣ����һ�ˡ������������ǣ�
������һ���޼ʵĴ󺣡�
LONG );
        set("exits", ([
                "west" : __DIR__"stdongjie1",
	]));

	set("outdoors", "����");

	set("item_desc", ([
                "chuan" : "һ�Ҵ󷫴�����úܽ�ʵ���������Գ�Զ���ġ�\n",
	]));
	set("objects", ([
                "/d/city2/npc/flowerg":2,
		__DIR__"npc/shuibing" :3,
		"/d/shenlong/npc/chuanfu" :1,
//		"/d/binghuodao/npc/chuanfu" :1,
"/clone/master/master"+(random(24)+1): random(2),
	]));
//	set("no_clean_up", 0);
	set("outdoors", "city2");
	setup();
//	replace_program(ROOM);
}

void init()
{
    add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
    object ob ;
    string dir;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
         return 1 ;
       }
    ob = this_player () ;
    if( ob->query("family/family_name") != "������")
{
     message_vision("$N���������̵Ŀ촬,�㲻����!\n",  ob);
    return 1;
}
    message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
    message_vision("�������𷫣��촬���򶫷����С�\n", ob);
    ob->move("/d/shenlong/haitan") ;
    tell_object(ob, BLU "���ں��Ϻ�����һ��͵���һ������!\n" NOR ) ;
    return 1 ;
}