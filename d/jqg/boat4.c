// boat4.c ����
// By River 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","С��");
        set("long", @LONG
������һҶ����֮�ڣ�������С�쳣�����Ҳ�����ض��������ˡ���˫
�ְ⽰��������˳Ϫ���¡�
LONG
        );
        set("outdoors","�����"); 

        setup();
}

void init()
{
       object me= this_player();
       add_action("do_quit","quit");
       call_out("run",15, me);
}

void run(object me)
{
        if (environment(me)== this_object())
        environment(me)->set("ppl",0);
        write(HIC"\n\nԶɽ���̣�Ϫˮտ��������Զɽ��ӳ��տ����Ϫˮ�У��������̣���Ũ������\n"+
                 "Ϫ�����ۣ�С�۾������˼�������������ܿ���Ϫ�԰�������������ټ���\n\n"NOR);
        me->move(__DIR__"boat5");
}

int do_quit()
{
        write("���ﲻ׼�˳���\n");
        return 1;
}
