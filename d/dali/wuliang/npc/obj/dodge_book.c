// by cool 980719
// Modify By River 98/12
#include <ansi.h>
inherit ITEM;
void init()
{
        add_action("do_du", "read");
     	add_action("do_fan", "fan");	
     	add_action("do_fan", "find");
	add_action("do_lingwu", "study");
        add_action("do_lingwu", "lingwu");
}

void create()
{
        set_name(HIW"����"NOR, ({ "bo juan", "bojuan", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���õĲ������ӵĲ��Ƴ���\n"); 
                set("unique", 1);
                set("treasure", 1);
                set("material", "silk");
		set("book_fan",4);
                set("no_drop", "�������������뿪�㡣\n");
                set("no_get", "�������������뿪�Ƕ���\n");
        }
}

int do_du(string arg)
{
        object me = this_player();
        mapping skill;      
        if (!(arg=="bo juan" || arg == "bojuan" || arg == "book"))
        return 0;
        if( me->is_busy()) 
            return notify_fail("��������æ���ء�\n");
        if( me->is_fighting() ) 
            return notify_fail("���޷���ս����ר�������ж���֪��\n");
        if(!id(arg))
             return notify_fail("��Ҫ��ʲô��\n");
        if(!me->query("dali/meet_dy1") || !me->query("dali/pass"))
             return notify_fail("����˺�����߰��㣬ʲô�������壬���޷�������ѧ��������\n");
        if(!me->query_temp("book", 1))
             return notify_fail("����˺�����߰��㣬ʲô�������壬���޷�������ѧ��������\n");
	if((int)me->query("jing") < 25 )
             return notify_fail("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");        
	if((int)me->query("neili") < 35 )
             return notify_fail("�������������޷�ר�������ж���֪��\n");        
        if((int)me->query_int() < 34)
             return notify_fail("������Բ���������ô������书��\n");
        if((int)me->query_skill("literate", 1) < 100)
             return notify_fail("�㿴������������д�����֡�\n"); 
        if((int)me->query("max_neili") < 1200 )
             return notify_fail("��������Ϊ�������޷�������ô������书��\n");
        if((int)me->query("combat_exp")< 200000)
             return notify_fail("���ʵս���鲻�����޷�������ô������书��\n"); 
        if( me->query_skill("lingboweibu", 1) > 60)
	     return notify_fail("���ж���һ������������Ͻ��Ĳ�����������������е���ϰ���޷����ġ�\n");
          me->receive_damage("jing", 15);
          me->add("neili",-(int)me->query_skill("lingboweibu", 1)/2);  
          me->improve_skill("lingboweibu", (int)me->query_skill("literate", 1)/3+1);
          write("����ϸ�ж��Ų����ϵĲ�����\n");
         return 1;
}

int do_fan(string arg)
{
       object me = this_player();        		       
       if (!(arg=="bo juan" || arg == "bojuan" || arg == "book"))
           return 0;
       if ( me->is_busy()) 
           return notify_fail("��������æ���ء�\n");
       if( me->is_fighting() ) 
           return notify_fail("���޷���ս������������顣\n");
       if (!id(arg))
           return notify_fail("��Ҫ��ʲô��\n");
       if( me->query_temp("book"))
           return notify_fail("���Ѿ��ҵ�����Ҫ���ˡ�\n");
       if (me->query_temp("find") < 3 ){
         write("����ϸ�����ű�˺�����õĲ���ϣ���ܴ����ҳ���ʲô��\n");
         me->add_temp("find", 1);         
         return 1;
         }
         write("�㷭����󣬲��ɵô�Ϊ��ϲ���ⲿ�ֲ�û�б�˺�ã����š��貨΢�������֣�\n"+
               "�������������ӡ��ע�������á������������ȵ������������׾��еķ�λ��\n"+
	       "ֻ����ӡ�������飬��֪�м�ǧ�ٸ�����һ����ӡ����һ����ӡ�������߹ᴮ��\n"+
	       "���ϻ��м�ͷ������һ�׷����Ĳ��������д��һ���ֵ��������ǿ�У��Դ� \n"+
	       "����������������ȡ��������\n");
	 me->set_temp("book", 1);
         me->delete_temp("find");
         return 1;	    
}

int do_lingwu(string arg)
{
	object me = this_player();
	int level, jingcost;
        if ( !arg ) return 0;
        if (!(arg == "bo juan" || arg == "bojuan" || arg=="book"))
	   return notify_fail("��Ҫѧʲô��\n");
	  level = me->query_skill("lingboweibu", 1);
	if (level > me->query_skill("dodge", 1))  
           return notify_fail("���ȴ���Ṧ�ĸ����ɣ�\n");
	if ( !me->is_fighting())
           return notify_fail("����ñ�����ս��������\n");
        if ( level <= 100 ) {
	  jingcost = level / 3 + random(level / 3);
	if (me->query("jing") <= jingcost)
           return notify_fail("��̫ƣ���ˣ���ЪЪ�ɣ�\n");
        if (me->query("neili") < 20)
           return notify_fail("���������������ЪЪ�ɣ�\n");
          me->receive_damage("jing", jingcost);
          me->add("neili",-random(20));
	  me->improve_skill("lingboweibu", (int)me->query_skill("literate", 1)/3+1);
	  message_vision("$Nս���б���˫�ۣ������Ų����ϵĲ�����\n", me);
	  return 1;
	  }
      return notify_fail("���Ѿ������еľ��趼�����ˡ�\n");
}
