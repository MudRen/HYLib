// /d/tiezhang/zhaigou4.c

#include <ansi.h>
inherit ROOM;

void create()
{

          set("short","կ��");
          set("long", @LONG
����ɽ�Ŷ��ߵ�կ����ǰ����һ�����կ������һ�Ŵ�ľ׮�ô�������
�����ģ����ںܳ�ʱ��û�н������ɺ͹ٸ������ư����˻�Ѱ������կ��
��ľͷ��Щ�Ѿ������ˣ���Щ�Ѿ��ɶ��ˡ�
LONG
);

            set("exits",([
  "west": __DIR__"zhaigou3",
            ]));

            set("outdoors","tiezhang");
     
            setup();
//            replace_program(ROOM);
}
void init()
{
        add_action("do_repair","repair");
        add_action("do_repair","bu");
}

int do_repair(string arg)
{    
        mapping fam;
        object me,ob,weapon;
        int costj, costq;
        me = this_player();
        if(me->query_temp("job_name")!="��կ��") 
             return notify_fail("���������������⹤�������������! \n");
        if (me->is_busy())
             return notify_fail("��������æ����!\n");
        if (me->is_fighting())
             return notify_fail("������ս����,�޷�ר�ĸɻ�!\n");
        weapon = me->query_temp("weapon");
        if( !weapon || weapon->query("id") != "tie chui")
             return notify_fail("������ʲô������\n");
        if ( !arg ||!(arg == "կ��" || arg == "zhailan"))
           return notify_fail("����Ҫ��ʲô��\n");
             
        costj = random((int)me->query("con")/2);
        costq = random((int)me->query("str")/2);

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
          {
          message_vision(HIR"$N����̫ƣ���ˣ�һ�����������������Լ��Ľ�ֺ�ϡ�\n"NOR,me);
          me->unconcious();
          return 1;
          }        
          me->receive_damage("jing", costj);
          me->add("qi", -costq);       
        if (((int)me->query_temp("mark/��կ��") > 8 + random(13)))
          {
          me->set_temp("mark/����",1);
          write(HIG"�㷢�ֻ������Ѿ���կ���޲��ò���ˣ�Ӧ�û�ȥ������!!\n"NOR);
          return 1;
          }  
          write ("����������������޲���կ������\n");
          me->start_busy(1);
          me->add_temp("mark/��կ��",1);
          return 1;
}