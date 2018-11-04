#include <ansi.h>

#define SHIP_TO __DIR__"xingxingtan"

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();


void create()
{
        set("short", "��̲");
        set("long", @LONG
��Ƭ��̲��ʱ�����½̽��ڳ˴�(chuan)������̲ͷ����һ�����½̵�
���ģ��������������½̵������Ƶģ����Ծ��ܽ����������Ĵ�ֻ��
�࣬���ǲ�û�д���������ͣ����Ҫ���԰�ֻ�п����½��Լ��Ĵ�ֻ
�ˡ�
LONG
        );
    set("exits", ([
        "westup" : __DIR__"shandao1",
    ]));
    set("item_desc", ([
        "he" : "һҶС�۾�ɭɭ�ؿ���«έ�ϣ���(yell)һ���Կ���\n",
    ]));
    set("objects", ([
        "quest/menpaijob/riyue/huangboliu" : 1,
        __DIR__"npc/heiyiren" : 2,
    ]));
    set("no_clean_up", 0);
    set("outdoors", "heimuya");
    setup();
}

/*�ڴ˸�Ǯ�ڶɻ������*/
/*���ȣ��ɴ����˰�������Ǯ������һ��ߺ�ȣ�������һӿ
 * ���룬СС�ɴ�Ƭ�̼��Խ���������εĺ��������ϱ���
 */
void init()
{
        add_action("do_yell", "yell");
        add_action("du_jiang", "dujiang");
}

void check_trigger()
{
        object room;
        object thisroom = this_object();

        if(!query("exits/enter") ) {
                if( !(room = find_object(__DIR__"duchuan")) )
                        room = load_object(__DIR__"duchuan");
                if( room = find_object(__DIR__"duchuan") ) {
                        if((int)room->query("yell_trigger")==0 ) {
                                room->set("yell_trigger", 1);
                                set("exits/enter", __DIR__"duchuan");
                                room->set("exits/out", __FILE__);
                                message("vision", "һҶ���ۻ�����ʻ�˹�����������һ��̤�Ű���ϵ̰����Ա�˿����¡�\n", thisroom);
                                message("vision", "������һ��̤�Ű���ϵ̰����γ�һ�����ϵĽ��ݡ�\n", room);
                                remove_call_out("on_board");
                                call_out("on_board", 15);
                        }
                        else
                                message("vision", "ֻ���ý�������������������������æ���š�����\n", thisroom);
                }
                else
                        message("vision", "ERROR: boat not found\n", thisroom);
        }
        else 
                message("vision", "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n", thisroom);
}

void on_board()
{
        object room;

        if( !query("exits/enter") ) return;

        message("vision", "������̤�Ű��������������һ�㣬��������ʻȥ��\n", this_object());

        if( room = find_object(__DIR__"duchuan") )
        {
                room->delete("exits/out");
                message("vision", "������̤�Ű���������˵��һ��������ඡ������һ�㣬��������ʻȥ��\n", room);
        }
        delete("exits/enter");

        remove_call_out("arrive");
        call_out("arrive", 6);
}

void arrive()
{
        object room;

        if( room = find_object(__DIR__"duchuan") )
        {
                room->set("exits/out", SHIP_TO);
                message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n", room);
        }
        remove_call_out("close_passage");
        call_out("close_passage", 10);
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
        object me = this_player();

        if (!arg) return 0;

        if (arg == "boat") arg = "����";
        if (me->query("age") < 16  )
                message_vision("$Nʹ�����̵���������һ������" + arg + "��\n", me);
        else if (me->query("neili") > 500)
                message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ���˳�ȥ��\n", me);
        else
                message_vision("$N������������Хһ������" + arg + "����\n", me);
        if (arg == "����")
        {
                check_trigger();
                return 1;
        }
        else
                message_vision("������ԶԶ����һ���������" + arg + "��������\n", me);
        return 1;
}

void reset()
{
        object room;

        ::reset();
        if (room = find_object(__DIR__"duchuan"))
                room->delete("yell_trigger"); 
}

int du_jiang()
{
        object me = this_player();

        if (!living(me)) return 0;
        if (me->query_skill("dodge") < 150)
                return notify_fail("�����Ϊ������\n");
        tell_room(environment(me), HIG + me->name() + "����һ��«έ����ˮ�У������ŷ���Ծ��«έ������ƮƮ���ɹ��˺�ˮ��\n" NOR, ({me}));
        write("��ʹ����һέ�ɽ����ɹ��˺�ˮ��\n");
        me->move(SHIP_TO);
        tell_room(environment(me), HIG "ֻ��" + me->name() + "����һ��«έ�Ӷ԰���������̬���������ڰ��ߡ�\n" NOR, ({me}));
        return 1;
}

