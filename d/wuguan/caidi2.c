#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�˵�");
	set("long", @LONG
�����ǿ�˵أ��˵����м��ڴ�ף�����ʢ����ˮ�����ǲ˵ؿ�����
�������ˣ����ò�����ĳ��ţ���������ȱˮ̫���ˡ�
LONG);
	set("exits", ([
	    "east" : __DIR__"houyuan3",
        ]));
        set("objects", ([
           __DIR__"npc/guanjia6" : 1,
        ]));
 	setup();
}

void init()
{
        add_action("do_jiao", "jiao");
        add_action("do_jiao", "��");     
}
int do_jiao(string arg)
{      
        object me,weapon;
        int costj, costq;
        me = this_player();

        if(me->query_temp("job_name")!="���˵�") 
             return notify_fail("���������������⹤������������ɻ\n");
        if (me->is_busy()) return notify_fail("��������æ���أ�\n");
        if (me->is_fighting()) return notify_fail("������ս���У��޷�ר�ĸɻ\n");
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("id")!= "piao")
		return notify_fail("������ʲô��Ҩˮ����������\n");

        if ( !arg || arg != "ˮ" ) return notify_fail("��Ҫ��ʲô��\n");

        costj = random((int)me->query("con")/3)+1;
        costq = random((int)me->query("str")/3)+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
              message_vision("$N�����������Ҩˮ�����һʧ���Խ��˸��\n",me);
              me->set("water", 350);
              me->unconcious();
              return 1;
              }
        
        me->receive_damage("jing", costj);
        me->receive_damage("qi", costq);       

        if (!(int)me->query_condition("wuguan_job")
            &&(int)me->query_temp("mark/��") > 10+(random(5))
            && present("caiyuan guanshi", environment(me))){
                me->set_temp("mark/������",1);
		message_vision(RED"��԰���¶�$N˵���ɵĲ������ˣ�����Ի�ȥ������task ok)�ˡ�"NOR, me);
                return 1;
                }
	message_vision("$N��ư�Ӹ���Ҩ��ˮ���ڲ˵��ｽ��ˮ���� \n", me);
        me->add_temp("mark/��",1);
        return 1;
}

