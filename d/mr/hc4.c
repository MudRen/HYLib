// /u/beyond/mr/hc4.c 
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"������"NOR);
         set("long",@long
���Ų�����, ֻ�������г�ɽ�軨����ޱ�������, �������ǣţ��,
���º�, Ǿޱ֮��Ҳ��һ�䶼�ޡ��߳���ʮ�ɺ�, ֻ��ɽ��Ʒ�ֽ���, ż��
Ҳ��һ�������㲻��, ȴҲ���ֲ����䷨���������ǰԺ��
long);
         set("outdoors","mr");
         set("exits",([
             "south" : __DIR__"qianyuan",
             "west" : __DIR__"hc1",
]));
         setup();
//         replace_program(ROOM);
}
void init()
{
        add_action("do_dig","jiaoshui");
}

int do_dig(string arg)
{    
        mapping fam;
        object me,ob,weapon;
        int costj, costq;
        me = this_player();
        if(me->query_temp("mr_job")!="����") 
             return notify_fail("��������͸�? \n");
        if (me->is_busy())
             return notify_fail("��������æ����!\n");
        if (me->is_fighting())
             return notify_fail("������ս����,�޷�ר�ĸɻ�!\n");
        weapon = me->query_temp("weapon");
        if( !weapon || weapon->query("id") != "shui hu")
             return notify_fail("������ʲô����������\n");
        if ( !arg || !(arg == "��" || arg == "hua"))
           return notify_fail("����Ҫ��ʲô��\n");
             
        costj = random((int)me->query("con")/2);
        costq = random((int)me->query("str")/2);

        if ((int)me->query("jing") < costj 
         || (int)me->query("qi") < costq){
          message_vision(HIR"����$N̫ƣ���ˣ�$Nһ����С�Ļ��˹�ȥ��\n"NOR,me);
          me->unconcious();
          return 1;
          }        
          me->receive_damage("jing", costj);
          me->add("qi", -costq);       
        if (((int)me->query_temp("mark/����") > 10 + random(13)))
          {
          me->set_temp("mark/����",1);
          write(HIG"���еĻ��㶼����һ�飬�㿴�Ż�Ц��Ц���,��ȥ������!!\n"NOR);
          return 1;
          }  
          write ("������ˮ�����ڻ�����һ��һ���Ľ�������\n");
          me->start_busy(1);
          me->add_temp("mark/����",1);
          return 1;
}