#include <ansi.h>

inherit ROOM;

void home( object ob ) ;

void create()
{
    set("short", "��̲");
    set("long", @LONG
��������������ˡ��ϱ���һ���޼ʵĴ󺣣���������һƬ��ľ�֡�
���ϵĿ����ƺ���������, ��ʪ�ĺ����д���һ���ȳ�, �ּ�����һ����
�صĻ���, ������ʮ�ֹ��졣���߲���һ�Ҵ�(chuan)��
LONG );

    set("item_desc", ([
        "chuan" : "����������������ϵ�Ĵ󴬡����ϵĿ��˻����ֻҪ\n"
                  "�ϴ�(enter)�Ϳ��Ի���ԭ��\n",
    ]));
    set("exits",([
        "south" :__DIR__"treen1",
        "north" :__DIR__"lin1",
        "east" :"/quest/menpaijob/shenlong/dian",
    ]));
	set("objects", ([
		"quest/skills2/wunon/yu/yutan" : 3,
	])); 

    set("outdoors", "shenlong");
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
    message_vision("�������𷫣��������������С�\n", ob);
    ob ->move(__DIR__"dahai") ;
    tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("home", 10 , ob );
    return 1 ;
}
void home( object ob )
{
  tell_object(ob , "�����ڵִ�����ԭ��һ���������С������´�����\n" ) ;
  ob->move ("/d/tanggu/gangkou") ;
}
