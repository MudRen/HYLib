//daoju.c ��Ϸ�õĵ���
//����II���������䣩
//����lywin 2000/6/20

#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_changxi", "changxi");
}

void create()
{
	set_name("��Ϸ����", ({"changxi daoju", "daoju"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_drop","��Ҫ�Ҷ���Ҫ��ģ�\n");
		set("no_put",1);
		set("long", "����һ�׳�Ϸ�õĵ��ߣ��������������Ϸ��changxi����\n");
		set("value", 0);
	}
	setup();
}

int do_changxi(string arg)
{
        object me=this_player();

    if (me->is_fighting()) 
        {
          tell_object(me,"���������������!\n");
          return 1;
        }
    if(me->is_busy())
        {
          tell_object(me,"����æ����!\n");
          return 1;
        }

        if (me->query_temp("obj/done") >= 1)
        {
          tell_object(me,"���ѳ���Ϸ�ˣ���ȥ����ɡ�\n");
          return 1;
        }
        else
        if (me->query_temp("obj/changxi") < 1)
        {
          tell_object(me,"���ں��񲻸��㳪Ϸ�ɣ�\n");
          return 1;
        }
        else
        if (!environment(me)->query("outdoors"))
        {
          tell_object(me,"�㲻���������Ϸ�ɣ�\n");
          return 1;
        }
        else
        if (me->query_temp("obj/where") != environment(me)->query("outdoors"))
        {
          tell_object(me,"�㲻���������Ϸ�ɣ�\n");
          return 1;
        }
        else
        if (environment(me)->query_temp("changxi") >= 1)
        {
          tell_object(me,"�������ǰ����������Ϸ�������ٳ�ֻ��û�˻�����\n");
          return 1;
        }
        else          
        if ((me->query("jing") < 20))
        {  
          tell_object(me,"��ľ������ܼ��У������Ա��ݣ�\n");
          return 1;
        }
        else
        if ((me->query("qi") < 30 ))
        {
          tell_object(me,"�������״̬̫����ܱ��ݣ�\n");
          return 1;
        }
        else          
	if (environment(me)->query_temp("changxi") >= 1)
        {
        tell_object(me,"�ող��������������Ϸ�ˣ����Ƕ������ٿ�Ϸ��\n"NOR,me);
       	return 1;
      	}
      	else
        if (!arg || arg == "" )
        { 
          tell_object(me,"��Ҫ�������ֱ��ݣ�
          ������changqu������ש��suizhuan������������zhou����\n");
          return 1;
        }
        else
        if ( arg == "changqu" )
        {
          if ((me->query("neili") < 30))
            return notify_fail("��������������Ϣ�Ƴ�������������㣬������������\n");
           
          message_vision(HIW"$N���������ӣ����Ƶĳ�����������\n"NOR,me);          
          me->start_busy(8); 
          call_out("changqu",8,me);
          return 1;
       	}
       	else
        if ( arg == "suizhuan" )
        {
          if ((me->query_skill("unarmed") < 30))
            return notify_fail("���ȭ�Ź����㣬�����ö���ʯ��\n");
            
          message_vision(HIW"$N�˹��ڱۣ�������һ��שͷ��ȥ��\n"NOR,me);          
          me->start_busy(8); 
       	  call_out("changqu",8,me);
       	  return 1;
       	}
       	else
        if ( arg == "zhou" )
        {
          if ((me->query_skill("dodge") < 30))
            return notify_fail("�����������ṦҲ��ȥ�������²�һ���Ӿ͵���������\n");

          message_vision(HIW"$N������һ����ҵ�����������ͷ����ͷ��ȥ��\n"NOR,me);          
          me->start_busy(8); 
       	  call_out("changqu",8,me);
       	  return 1;
       	}
}

int changqu(object me)
{
        message_vision(HIY"$Nһ�����ϣ��Աߵ��˹������ơ�\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("changxi",1);        
        return 1;
}

int suizhuan(object me)
{
        message_vision(HIY"$Nֻ���ô�Ŀ�שͷӦ�����飬���˿����Ŵ��˵����������\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("changxi",1); 
        return 1;
} 

int zhou(object me)
{
        message_vision(HIY"$N����������������˹�ȥ����Ҳû��һ�£����˶�����Ŀ�ɿڴ���\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("changxi",1); 
        return 1;
}          