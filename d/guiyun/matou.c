// Room: /guiyun/matou.c
// Date: Nov.18 1998 by Winder
#include <ansi.h>
#define SHIP_TO "/d/yixing/taihu"
inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
	set("short", "��ͷ");
	set("long", @LONG
����һ���ڽ���ˮ�缫��������ͷ���ɴֲڵĴ�����ʯ��ɡ�
�����ƺ���һ�������ׯԺ������ͣ��һ�Ҵ��洬(ship)������б
�ң��緫���ţ��������Ӳ���Ϊ�˳�������������ս�õġ�
LONG );
        set("outdoors", "guiyun");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"ship" : "����̫��ˮ���ٸ���ƶ��ս������ȥ(shang ship)�ͳ�����\n",
	]));
	set("exits", ([
		"north"     : __DIR__"damen",
	//"east"     : "/d/yixing/taihu",
	]));
	setup();
}
void init()
{
	add_action("do_yell", "yell");
	add_action("do_shang", "shang");
}

/*�ڴ˸�Ǯ�ڶɻ������*/
/*���ȣ��ɴ����˰�������Ǯ������һ��ߺ�ȣ�������һӿ
 * ���룬СС�ɴ�Ƭ�̼��Խ���������εĺ��������ϱ���
 */

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"duchuan")) )
            room = load_object(__DIR__"duchuan");
        if( room = find_object(__DIR__"duchuan") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤��"
                    "����ϵ̰����Ա�˿�\n���¡�\n", this_object() );
                message("vision", "������һ��̤�Ű���ϵ̰����γ�һ������"
                    "�Ľ��ݡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "ֻ���ú��������������������"
                    "�����æ���š�����\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "������̤�Ű��������������һ�㣬���������ʻȥ��\n",
        this_object() );

    if( room = find_object(__DIR__"duchuan") )
    {
        room->delete("exits/out");
        message("vision", "������̤�Ű���������˵��һ��������ඡ���"
            "���һ�㣬������\n����ʻȥ��\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"duchuan") )
    {
        room->set("exits/out","/d/yixing/taihu");
        message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű�"
            "���ϵ̰���\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
        object room, *ob;
        int i;

        if( room = find_object(__DIR__"duchuan") ) {
                room->delete("exits/out");

                tell_room(room, "��������˵���������´��ɣ���ҲҪ��ȥ�ˡ���\n", ({}));
                ob = all_inventory(room);
                for(i = 0; i < sizeof(ob); i++) {
                        if (userp(ob[i])) {
                                if (!living(ob[i])) tell_room(room, "������$Ņ���˴���\n", ob[i]);
                                else tell_room(room, "���������Ļ����ԹԵ����˴���\n", ob[i]);
                                ob[i]->move(SHIP_TO);
                                if (!living(ob[i])) tell_room(SHIP_TO, ob[i]->name() + "��̧���˴���\n", ({ob[i]}));
                                else tell_room(SHIP_TO, ob[i]->name() + "�����˴���\n", ({ob[i]}));
                        }
                }
                message("vision", "������̤�Ű����������ѱ���ʻ���ġ�\n", room);
                room->delete("yell_trigger"); 
        }
}

int do_yell(string arg)
{
    string dir;

    if( !arg || arg=="" ) return 0;

    if( arg=="boat" ) arg = "����";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$Nʹ�����̵���������һ������" + arg + "��\n",
            this_player());
    else if( (int)this_player()->query("neili") > 500 )
        message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ��"
            "�˳�ȥ��\n", this_player());
    else
        message_vision("$N������������Хһ������" + arg + "����\n",
            this_player());
    if( arg=="����")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("������ԶԶ����һ���������" + arg +
            "��������\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"duchuan") )
        room->delete("yell_trigger"); 
}

int do_shang ( string arg )
{
    object ob ;
    string dir;
    if( !arg || arg !="ship" ) 
    {
         tell_object(this_player() , "��Ҫ enter �Ķ���\n" ) ;
         return 1 ;
    }
    ob = this_player () ;
    message_vision("����Ⱥ��һ��$N�ϴ���æ����һ�����������ˣ�����ඣ�ɱ��ȥ��\n", ob);
    message_vision("�������𷫣���������к��С�\n", ob);
    ob ->move("/d/guiyun/ship") ;
    tell_object(ob, CYN "���ʴ��ں�������ǰ�У�ս������.......\n" NOR ) ;
    call_out("rjinbing", 10 , ob );
    return 1 ;
}
void rjinbing( object ob )
{
    string guanname;
    object ship, jinship,guan;
    if(!( ship = find_object("/d/guiyun/ship")) )
          ship = load_object("/d/guiyun/ship");
    if(!( jinship = find_object("/d/guiyun/jinship")) )
          jinship = load_object("/d/guiyun/jinship");

    tell_object(ob , "ս����һ����ɱ����ײ������һ�Ҵ󴬡�\n" ) ;
    ship->set("exits/out", "/d/guiyun/jinship" );
    jinship->set("exits/out", "/d/guiyun/ship" );
    
    if (ob->query("taohuajob") == 1 ) {
    
    guanname="/d/guiyun/guan"+random(9);
    if(!( guan = find_object(guanname)) )
          guan = load_object(guanname);
if (present("guan", guan))
{
    guanname="/d/guiyun/guan"+random(9);
    if(!( guan = find_object(guanname)) )
          guan = load_object(guanname);
}

if (present("guan", guan))
{
    guanname="/d/guiyun/guan"+random(9);
    if(!( guan = find_object(guanname)) )
          guan = load_object(guanname);
}

if (present("guan", guan))
{
    guanname="/d/guiyun/guan"+random(9);
    if(!( guan = find_object(guanname)) )
          guan = load_object(guanname);
}
if (present("guan", guan))
{
    guanname="/d/guiyun/guan"+random(9);
    if(!( guan = find_object(guanname)) )
          guan = load_object(guanname);
}
if (present("guan", guan))
{
    guanname="/d/guiyun/guan9";
    if(!( guan = find_object(guanname)) )
          guan = load_object(guanname);
}
//tell_object(ob , "ս����һ����ɱ����ײ������һ��"+guanname+"��\n" ) ;

if (!present("guan", guan))
{
	ob = new("/quest/menpaijob/taohua/guan");
	ob->move(guan);
	ob->set("startroom", base_name(guan));
}
    ship->set("exits/out", guanname );
    guan->set("exits/out", "/d/guiyun/ship" );
    }
}
