// boat1.c С��
// By River 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","С��");
        set("long", @LONG
������һҶ����֮�ڣ�������С�쳣�����Ҳ�����ض��������ˡ���˫
�ְ⽰����������Ϫ���С�
LONG
        );
        set("outdoors","�����"); 

        setup();
}

void init()
{
       object me= this_player();
       add_action("do_quit","quit");
       call_out("run", 15, me);
}

void run(object me)
{
        if (environment(me)== this_object())
        write(HIC"\n\n����һ��С���ѻ���һ����խ��Ϫˮ֮�У����벻�������Ȼ���ж��졣\n"+
                 "����ɽ�������Ϫ��ɽʯ��ˮ�治�����ߣ�����ú��Բ��У�С��ʼ�ܻ��롣\n"+
                 "̧ͷ���죬ֻ��һ�ߣ���ɫ�������ģ�ֻ�����¾�������Ϣ������͸�����ա�\n\n"NOR);
        me->move(__DIR__"boat2");
}

int do_quit()
{
        write("���ﲻ׼�˳���\n");
        return 1;
}
