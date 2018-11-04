// Room: /u/zqb/tiezhang/sslin-2.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "������");
	set("long", @LONG
���߽�һƬ��ѹѹ�������֣����������֦��Ҷï�����������������ա�
������������Ҽ������������ڵ����������У��γ�������ɫ�Ĺ�����ɷ�Ǻ�
�������������ţ���Ȼ�����Լ�����ʧ����Ƭ�����У��Ҳ�����ȥ��·�ˡ�
LONG
	);

	set("exits", ([ 
"north" : __DIR__"sslin-3",
"south" : __FILE__,
"west" : __DIR__"sslin-1",
"east" : __FILE__,
]));
	set("no_clean_up", 0);

	setup();
}
void init()
{
        add_action("do_fa","fa");
}

int do_fa(string arg)
{    
        mapping fam;
        object me,ob,weapon;
        int costj, costq;
        me = this_player();
        if(me->query_temp("job_name")!="��ľ") 
             return notify_fail("���������������⹤�������������! \n");
        if (me->is_busy())
             return notify_fail("��������æ����!\n");
        if (me->is_fighting())
             return notify_fail("������ս����,�޷�ר�ĸɻ�!\n");
        weapon = me->query_temp("weapon");
        if( !weapon || weapon->query("id") != "tie fu")
             return notify_fail("������ʲô����ľ��\n");
        if ( !arg || !(arg == "mu" || arg == "ľ"))
           return notify_fail("����Ҫ��ʲô��\n");
             
        costj = random((int)me->query("con")/2);
        costq = random((int)me->query("str")/2);

        if ((int)me->query("jing") < costj 
         || (int)me->query("qi") < costq){
          message_vision(HIR"����һ�ô�������$N���ϣ�$Nһ���ӱ������˹�ȥ��\n"NOR,me);
          me->unconcious();
          return 1;
          }        
          me->receive_damage("jing", costj);
          me->add("qi", -costq);       
        if (((int)me->query_temp("mark/��ľ") > 8 + random(13)))
          {
          me->set_temp("mark/����",1);
          write(HIW"�㷢�ֵ��ϵ�ľͷ���ÿ�����һ���ˣ�Ӧ�û�ȥ������!!\n"NOR);
          return 1;
          }  
          write ("�����������������������һ���¿�ȥ��\n");
          me->start_busy(1);
          me->add_temp("mark/��ľ",1);
        if ((int)me->query_skill("axe", 1) < 31 && random(10)>6 )
          {
          write(HIM"����ڻ�����������Щ���!\n"NOR);
          me->improve_skill("axe", (int)(me->query("int") / 10));
          }
          return 1;
}
