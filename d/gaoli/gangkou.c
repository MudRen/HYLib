// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
#include <ansi.h>

void create()	
{
	set("short", "�ۿ�");
	set("long", @LONG
������һ���ۿڣ�����ǳ����֣�ͣ���Ÿ��ִ�ֻ���л������̴�
�ȵȡ��ܶ��ÿʹ���������ۿڣ��д���ԭ���ģ�Ҳ�д������ط����ġ�
���С����������������۴�����ͨ���ձ�(chuan) ʮ�ַ��㡣
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"north" : __DIR__"dadi6",
//   "east":"/d/job/killhaidao/gangkou",
        	//"south":__DIR__"gangkou",
	]));
	set("item_desc", ([
                "chuan" : "һ���󺣴�����Զ��û�����Ĵ��ɲ��С�\n",
	]));
  	set("no_duhe",1);
       setup();
	
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
    message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
    message_vision("�������𷫣��������Ϸ����С�\n", ob);
    ob ->move("/d/quanzhou/dahai") ;
    tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("tpenghu", 10 , ob );
    return 1 ;
}
void tpenghu(object ob )
{
    tell_object(ob , "�����ڵִ��������������´�����\n" ) ;
    ob->move ("/d/japan/haigang") ;
}

