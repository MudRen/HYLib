// Room: /d/japan/haigang
inherit ROOM;
#include <ansi.h>
void create()
{
  set ("short", "����");
  set ("long", @LONG
����Ų�����ӿ���ձ���,��������Ե�ʮ��ƽ��,�ߴ��˫Φľ��
��������Ƭ����,����Ǹ�����洬,�����ʽ�����صĴ�ֻ,��Ȼ�Ǵ���
��������.���۴�����ͨ������(chuan) ʮ�ַ��㡣
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road",
]));
        set("objects", ([ /* sizeof() == 1 */
               __DIR__"npc/man" : 2,
            ]));
	set("item_desc", ([
                "chuan" : "һ���󺣴�����Զ��û�����Ĵ��ɲ��С�\n",
	]));            
  set("outdoors", "japan");
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
    message_vision("�������𷫣����������������С�\n", ob);
    ob ->move("/d/quanzhou/dahai") ;
    tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("tpenghu", 10 , ob );
    return 1 ;
}
void tpenghu(object ob )
{
    tell_object(ob , "�����ڵִ��˸����������´�����\n" ) ;
    ob->move ("/d/gaoli/gangkou") ;
}

