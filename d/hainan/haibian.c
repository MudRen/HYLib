// Room: /d/hainan/haibian.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ǰ����һ���޼ʵĴ�,����Ƕ��ͱ�����ʯ��.��Զ���ĺ�ˮ
��,һ���ʯ�ر�����עĿ,�������'���ĺ���'����.
�д�(chuan) ����ȥ���ϡ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shatan",
]));
	set("item_desc", ([
                "chuan" : "һ���󺣴���(enteran)���Ե�����.��Զ��û�����Ĵ��ɲ��С�\n",
	]));
  set("valid_startroom", 1);
	set("objects", ([ /* sizeof() == 1 */
"quest/skills2/wunon/yu/yutan" : 5,      
  __DIR__"npc/yuwen.c" : 1,
]));

	setup();
//	replace_program(ROOM);
}

void init()
{
    add_action("do_enter", "enteran");
}

int do_enter (string arg)
{
    object ob ;
    string dir;
    if( !arg || arg !="chuan" ) 
       {
         tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
         return 1 ;
       }
//    tell_object(this_player() , "�����ˣ�\n" ) ;
    ob = this_player();
    message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", ob);
    message_vision("�������𷫣����������Ϸ����С�\n", ob);
    ob ->move("/d/quanzhou/dahai") ;
    tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("tpenghu", 10 , ob );
    return 1 ;
}
void tpenghu(object ob )
{
    tell_object(ob , "�����ڵִ��˰��ϡ������´�����\n" ) ;
    ob->move ("/d/annan/matou") ;
}

