
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","������ͷ");
  set ("long", @LONG
�����ǰ��ϵ���ͷ���������ۿڣ��ڶ���ǣ�����Ҫ�ء�λ�ں��
�����޶����������ٱ����塣���ڰ��ߵĴ��������飬������õ�С�㴬��
�˻��õ��̴���������ͨ���ò���Ĺٴ������ϴ�������æ���쳣����
�ߺ����д�͵��̴����д�(chuan) ����ȥ�й����ϡ�
LONG);

  set("exits", ([ 
  "west":__DIR__"gj3",	
  "south":__DIR__"guandao4",
  "north":__DIR__"shulin3",	
       ]));
	set("item_desc", ([
                "chuan" : "һ���󺣴�����Զ��û�����Ĵ��ɲ��С�\n",
	]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
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
    message_vision("�������𷫣������򶫱������С�\n", ob);
    ob ->move("/d/quanzhou/dahai") ;
    tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("tpenghu", 10 , ob );
    return 1 ;
}
void tpenghu(object ob )
{
    tell_object(ob , "�����ڵִ����й����ϡ������´�����\n" ) ;
    ob->move ("/d/hainan/haibian") ;
}

