#include <ansi.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
        set("short", "��¥");
        set("long", @LONG
����һ��שľ�ṹ��С¥���������ᣬ�ܽ��Ϲ�����һ����Сͭ�壬
��綣�����졣ǽ���οյ�������������ǵ�����һ������̬άФ.
¥�ڸ�����һ������(zhong)�������Ӳ�����ǧ����������н��
���ģ�����һ�����죬�ڴ�����ڶ����ż���
LONG
        );

         set("exits", ([
                "west" : __DIR__"yaotai",
        ]));
set("item_desc",([
		"zhong"		:	"����Ӻܴ�ÿ�춼��������(qiao)��",
			]));


        set("outdoors", "������");
        setup();
}
void init()
{
	add_action("do_knock", "knock");
	add_action("do_knock", "qiao");
}

int do_knock(string arg)
{       
        mixed *local;
        object me,ob,weapon;
        int costj, costq;
        me = this_player();

	    local = localtime(time() * 60);
	            
        if (me->is_busy())
         { 
		 write("��������æ����!\n");
		 return 1;}
        if (me->is_fighting())
         {
		 write("������ս����,�޷�ר�ĸɻ�!\n");
		 return 1;
		 }
          
//        if (!( present("zhong chui", this_player())))
//		return notify_fail("�������£���Ȼ������ײ�����ӵġ�\n");

        if ( !arg || arg != "zhong" )
            {    write("��Ҫײʲô��\n");
                 return 1;
             }
        
		if (local[2] < 6 || local[2] >= 21) 
           {    
   message_vision("���ۡ�������һ��,һ��С����ͻȻ�����ܹ���˵������������Ϣʱ�䣬�������ӣ���\n"+
              "С���м�$N�����Ӵ������˸��������˳�ȥ��\n",me);
            return 1;
             }

        costj =  (int)me->query_con() / 2;
             costq = (int)me->query_str()/2;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
       {
        message_vision("����һ�죬$N���޴�ĺ�������Ļ��˹�ȥ��\n",me);
        me->unconcious();
        return 1;
        }
        if ((int)me->query_skill("force",1) < 60)
       {
        message_vision("���ۡ�������һ����$N����Ļ��˹�ȥ��\n",me);
        me->unconcious();
        return 1;
        }          
        me->receive_damage("jing", costj);
        me->add("qi", -costq);       

	message_vision("$N����һ�´��ӣ����ۡ���������������������\n", me);
		
     if ( (int)me->query_skill("force", 1) < 131 )
                {  write("�����������ǰ���Σ���������һ�����������ڹ��ֵ���\n");
                   me->improve_skill("force", (int)me->query("int"));
                } else {
			write("���������㲻�ɵ����а�������֮�ġ�\n");
		 	    }
          return 1;

}
