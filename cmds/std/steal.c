// steal.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
   string what, who;
   object ob, victim,obj;
   mapping myfam, vtfam;
   int sp, dp;

   if( environment(me)->query("no_fight")) return notify_fail("�����ֹ���ԡ�\n");
   if( environment(me)->query("no_steal")) return notify_fail("�����ֹ���ԡ�\n");

        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
//         write("������û�������������µ�½!!\n");
        return notify_fail("������û�������������µ�½!!\n");
        }

   if( me->query_temp("stealing") )
      return notify_fail("���Ѿ����һ��������ˣ�\n");

   if( !arg || sscanf(arg, "%s from %s", what, who)!=2 )
      return notify_fail("ָ���ʽ��steal <��Ʒ> from <����>\n");

   victim = present(who, environment(me));
   if( !victim || victim==me) return notify_fail("�������ԵĶ��������\n");
   if( !wizardp(me) && wizardp(victim) )
      return notify_fail("��Ҳ���͵��ʦ���ϵĶ�����\n");

    if((int)victim->query("age") <= 17 && userp(victim))
        return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");
    if( userp(victim) && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
    if( userp(victim) && victim->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
//   if( !ob->is_character()  )
//	return notify_fail("�����һ�㣬��ֻ�ܴ�������͵������\n");

   if( !victim->is_character() || victim->is_corpse() )
	return notify_fail("�����һ�㣬�ǲ����ǻ����get�ȽϺá�\n");
if(userp(victim) && victim->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("������ǿ̫�࣬�㲻�Ҷ��֡�\n");
   if( victim->query("race") != "����" )
        return notify_fail(victim->name() + "���������ˣ���kill�ȽϺã�\n");


//��սϵͳ
obj=victim;
        if (userp(me) && userp(obj)
         && obj->query_temp("nokill") )
        return notify_fail("������������ս�ƣ�\n");

        if (userp(me) && userp(obj)
         && me->query_temp("nokill") )
        return notify_fail("����������ս�ƣ�\n");

    if( userp(me) && userp(obj) && obj->query_condition("nokill")
    && !obj->query_condition("killer"))
        return notify_fail("�Ǹ��˸ձ�ɱ�����Ź����ɣ�\n");
if( !living(obj) && userp(obj) && obj->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("����Ҫɱ���ˣ���������ǿ̫�࣬�㲻�Ҷ��֡�\n");


   if( victim->query_temp("no_kill") )
        return notify_fail("���˲���steal��\n");
   if( victim->query("hunmi",1))
        return notify_fail("���������أ���get��\n");
    if(me->is_busy())
        return notify_fail("��������æ��\n");

   if( victim->query("disable_inputs",1))
        return notify_fail("��������ָ���أ�\n");
        if (userp(victim) && !query_heart_beat(victim))
        {
         write("������ʲô��\n");
        return notify_fail("���˲���steal��\n");
//         write("���˲���steal��\n");
        }

   if( userp(victim) && me->query("age")<18 && me->query("combat_exp")<50000)
           return notify_fail(victim->name() + "����ң�����������㣡\n");

    if( !ob = present(what, victim) )
   {
      object *inv;
      inv = all_inventory(victim);
      if( !sizeof(inv) )
         return notify_fail( victim->name() + "���Ͽ�����û��ʲ��ֵǮ�Ķ�����͵��\n");
      ob = inv[random(sizeof(inv))];
   }
    if(ob->query("dynamic_quest"))
{
        return notify_fail( victim->name() + "���Ͽ�����û��ʲ��ֵǮ�Ķ�����͵��\n");
}

   sp = (int)me->query_skill("stealing") * 5 + (int)me->query("kar") * 2
        - (int)me->query("thief") * 20;

   if ( (myfam = me->query("family")) && myfam["family_name"] == "ؤ��" )
      sp = (int)me->query_skill("stealing") * 10 + (int)me->query("kar") * 5
           - (int)me->query("thief") * 20;

   if( sp < 1 ) sp = 1;

   if( me->is_fighting() )
   {
       sp /= 2;
       me->start_busy(3);
   }
   dp = (int)victim->query("jing") * 2 + (int)ob->weight()/25;
   if( victim->is_fighting() ) dp *= 10;
   if( ob->query("equipped") ) dp *= 10;

   write("�㲻����ɫ����������" + victim->name() + "���ȴ��������� ...\n\n");
   if( ob->query("no_get",1))
   return notify_fail("�����������͵�����ģ�\n");
   if( ob->is_character() || ob->is_corpse() )
   return notify_fail("���ֶ�������͵�ġ�\n");

   me->set_temp("stealing", 1);
   ob->set("no_get",1);
   call_out( "compelete_steal", 3, me, victim, ob, sp, dp);

   return 1;
}

private void compelete_steal(object me, object victim, object ob, int sp, int dp
)
{
   mapping myfam, vtfam;
   int steal_level;
       int exp,pot;
        if (!me)  return notify_fail("���Ѿ������ˣ�\n");
        if (!victim)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");
   me->delete_temp("stealing");

   if( environment(victim) != environment(me) )
   {
      tell_object(me, "̫��ϧ�ˣ������ֵ�Ŀ���Ѿ����ˡ�\n");
      return;
   }
        if (!ob)  return notify_fail("���������Ѿ������ˣ�\n");
        ob->set("no_get",0);
   if( !living(victim) || (random(sp+dp) > dp) )
   {
        if (!ob)  return notify_fail("���������Ѿ������ˣ�\n");

      if( ob->query("no_steal") )
      {
         tell_object(me, "������һ" + ob->query("unit") + ob->name()
                       + "��������ͻȻ�������飬��Ȼ�������֣����ǿ�ϧ�ˡ�\n");
   ob->set("no_get",0);
         return;
      }

      if( ob->query("equipped") )
      {
         tell_object(me, "������һ" + ob->query("unit") + ob->name()
                       + "�������Ǽ�����,�˼��������ء�\n");
   ob->set("no_get",0);
            return;
      }
//	set_max_encumbrance(10000);
	if (ob->is_container() )
	{
	tell_object(me, "���Ǹ�����,��͵���˵�!\n");
   ob->set("no_get",0);
		return;
	}

        if (!ob)  return notify_fail("���������Ѿ������ˣ�\n");


               if (sizeof(all_inventory(me)) >= 40)
                {
                        tell_object(me, "�ۿ����Ҫ���֣���ϧ���ϵĶ�"
                                    "��̫�࣬ʵ���ò����ˡ�\n");
//                        ob->move(environment(me));
                        return;
                }

      if( !ob->move(me) )
      {
         tell_object(me, "������һ" + ob->query("unit") + ob->name()
                       + "�����Ƕ������̫���ˣ����ò�������\n");
   ob->set("no_get",0);
         return;
      }


      tell_object(me, HIW "�����ˣ�\n\n" NOR);
   ob->set("no_get",0);
      tell_object(me, "��ɹ���͵��һ" + ob->query("unit") + ob->name() + "��\n");
	if( userp(victim) && query_ip_name(victim)==query_ip_name(me) )
{
			message_vision(victim->name() + "��$Nһ�ۣ����ҹ�ϵ��ô�ã�����͵�ҵĶ�����\n", me);

} else
{
exp=18+random(30);
pot=15+random(12);
  if( me->query("family/family_name") == "ؤ��")
{
if (!userp(victim))
{
	   tell_object(me,HIW"�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);
		me->add("potential",pot);
		me->add("combat_exp",exp);
}
}
}

      steal_level = (int)me->query_skill("stealing",1);

      if( living(victim) )
      {
         if ((int)me->query("combat_exp") > (steal_level*steal_level*steal_level/10) )
         {
            me->improve_skill("stealing", random(me->query("int")));
         }
         else
         {
            tell_object(me," ����㾭��ҲҪȥ͵�� \n");
         }
         if ( (myfam = me->query("family")) && myfam["family_name"] == "ؤ��" )
         {
            if (( (int)me->query("potential") - (int)me->query("learned_points") < 100))
            {
               me->add("potential",1);
            }
//add by Java. Nov 16.1997
   if (!me) return notify_fail("���Ѿ������ˣ�\n");
            me->start_busy(2);
            me->add("thief", 1);
            me->add("jing",-10);
            me->add("eff_jing",-4);

            me->add("combat_exp",1);
         }
      }

      if( random(sp) < dp/2 )
         message("vision", "�㿴��" + me->name() + "�������ش�"
               + victim->name() + "����͵����һ" + ob->query("unit")
               + ob->name() + "��\n", environment(me), ({ me, victim }) );
   }
   else
   {
      if( random(sp) > dp/2 )
      {
         tell_object(me, victim->name() + "�������һתͷ���㼱æ�������˻�ȥ��\n"
            "���ã�û�б����֡�\n");
   ob->set("no_get",0);
         return;
      }
      tell_object(me, HIR "��⣡��ʧ���ˣ�\n\n" NOR);
      message_vision("$Nһ��ͷ�����÷���$n������ץ��$P���ϵ�" + ob->name() + "��\n\n"
            + "$N�ȵ�������ʲô����\n\n", victim, me);
   if (!me) return notify_fail("���Ѿ������ˣ�\n");
   ob->set("no_get",0);
if (me->query_skill("stealing"))
{
      me->improve_skill("stealing", 1, 1);
}
      if( userp(victim) ) me->fight_ob(victim);
      else me->kill_ob(victim);
      me->start_busy(3);
      me->add("thief", 1);
      me->add("jing",-10);
      me->add("eff_jing",-4);
   }

}

int help(object me)
{
write(@HELP
ָ���ʽ : steal <ĳ��> from <ĳ��>

���ָ�������л���͵���������ϵĶ������ɹ���, ��Ȼ����ܻ��
������Ʒ������, ����ʧ��, ������ʧ���ʱ��, ����ʧ��ʱ��Ȼ��
�ø�������, �����ʲô����......�����Լ�ȥ�����ޡ�
HELP
    );
    return 1;
}

