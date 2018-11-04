// Room: /d/tiezhang/shanlu-1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ����᫵�ɽ·�ϣ�����ɽ����������ݹ������м�һ����С·��
����һ����ǿ��ȥ��
LONG
	);
    
        set("outdoors", "tiezhang");
	
        set("exits", ([ 
"north" : __DIR__"shanlu-2",
"southdown" : __DIR__"shanmen.c",
]));
	set("no_clean_up", 0);

	setup();

}
void init()
{
        add_action("do_dig","wa");
        add_action("do_dig","dig");
}

int do_dig(string arg)
{    
        mapping fam;
        object me,ob,weapon;
        int costj, costq;
        me = this_player();
        if(me->query_temp("job_name")!="���ݾ�") 
             return notify_fail("���������������⹤�������������! \n");
        if (me->is_busy())
             return notify_fail("��������æ����!\n");
        if (me->is_fighting())
             return notify_fail("������ս����,�޷�ר�ĸɻ�!\n");
        weapon = me->query_temp("weapon");
        if( !weapon || weapon->query("id") != "tie chan")
             return notify_fail("������ʲô���ڣ�\n");
        if ( !arg || !(arg == "�ݾ�" || arg == "xianjing"))
           return notify_fail("����Ҫ��ʲô��\n");
             
        costj = random((int)me->query("con")/2);
        costq = random((int)me->query("str")/2);

        if ((int)me->query("jing") < costj 
         || (int)me->query("qi") < costq){
          message_vision(HIR"����$N̫ƣ���ˣ�$Nһ����С�ĵ������Լ��ڵ��ݾ��С�\n"NOR,me);
          me->unconcious();
          return 1;
          }        
          me->receive_damage("jing", costj);
          me->add("qi", -costq);       
        if (((int)me->query_temp("mark/���ݾ�") > 8 + random(13)))
          {
          me->set_temp("mark/����",1);
          write(HIG"�㷢���ݾ����ںã��Ͻ���һЩ�ɲ������ݾ��ϣ���ȥ������!!\n"NOR);
          return 1;
          }  
          write ("����������������ڵ���һ��������������\n");
          me->start_busy(1);
          me->add_temp("mark/���ݾ�",1);
          return 1;
}