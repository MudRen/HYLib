// beg.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string what, who;
        object ob, victim,obj;
        mapping myfam, vtfam;
        int sp, dp;

        object where = environment(me);

        seteuid(getuid());

        if ( (!(myfam = me->query("family")) || myfam["family_name"] != "ؤ��"))
          return notify_fail("ֻ����ؤ�������֣�\n");

        if( environment(me)->query("no_beg") || environment(me)->query("no_fight"))
                return notify_fail("���ﲻ����л��������ַ��ĵط���\n");

        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
//         write("������û�������������µ�½!!\n");
        return notify_fail("������û�������������µ�½!!\n");
        }

        if( me->query_temp("begging") )
                return notify_fail("���Ѿ������˼������ˣ�\n");

        if( !arg || sscanf(arg, "%s from %s", what, who)!=2 )
                return notify_fail("ָ���ʽ��beg <��Ʒ> from <����>\n");

        victim = present(who, environment(me));
        if( !victim || victim == me) return notify_fail("�������ֵĶ��������\n");
        if( !living(victim) || !objectp(victim)) return notify_fail("��Ҫ��˭���֣�\n");
        if ( (vtfam = victim->query("family")) && vtfam["family_name"] == "ؤ��" )
                return notify_fail("�㲻������ؤ���֣�\n");

        if( !wizardp(me) && wizardp(victim) ) return notify_fail("��Ҳ�������ʦ���֡�\n");

        if( me->is_fighting() )
                return notify_fail("һ�ߴ��һ��Ҫ���������ǻ����ˣ�\n");

        if( victim->is_fighting() )
                return notify_fail(victim->name() + "���ڴ�ܣ�û�����㣡\n");
        if( victim->query_temp("no_kill") )
        return notify_fail("���˲���beg��\n");
   if( victim->query("hunmi",1))
        return notify_fail("���������أ���get��\n");
   if( victim->query("disable_inputs",1))
        return notify_fail("��������ָ���أ�\n");
    if(me->is_busy())
        return notify_fail("��������æ��\n");
    if( userp(victim) && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
    if( userp(victim) && victim->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("���Ѿ���ͨ���ˣ���Ҫ����ɱ����ˣ�\n");
if(userp(victim) && victim->query("combat_exp")/2 > me->query("combat_exp") )
	return notify_fail("������ǿ̫�࣬�㲻�Ҷ��֡�\n");


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
	

        if (userp(victim) && !query_heart_beat(victim))
        {
         "/cmds/usr/quithy"->main(victim);
        return notify_fail("���˲���beg��\n");
//         write("���˲���beg��\n");
        }



        if( !victim->is_character() || victim->is_corpse() )
	return notify_fail("�����һ�㣬�ǲ����ǻ����get�ȽϺá�\n");

        if( victim->query("race") != "����" )
                return notify_fail(victim->name() + "���������ˣ��������㣡\n");
//userp(obj)
        if( userp(victim) && me->query("age")<18 && me->query("combat_exp")<50000)
                return notify_fail(victim->name() + "����ң�����������㣡\n");


        if( !ob = present(what, victim) ) {
                object *inv;
                inv = all_inventory(victim);
                if( !sizeof(inv) )
                        return notify_fail( victim->name() + "���Ͽ�����û��ʲ���������Ȥ�Ķ�����\n");
                ob = inv[random(sizeof(inv))];
        }

        if ( ob->query("equipped") || ob->query("no_drop") )
                return notify_fail("�������˵�����һ�϶�������㡣\n");

	if (ob->is_container() )
	{
                return notify_fail("���Ǹ��������϶�������㡣\n");
	}

        if(ob->query("dynamic_quest"))
	{
               return notify_fail( victim->name() + "���Ͽ�����û��ʲ���������Ȥ�Ķ�����\n");
	}

        if( ob->query("no_beg"))
        return notify_fail("������������ֲ����ģ�\n");

   if( ob->is_character() || ob->is_corpse() )
   return notify_fail("���ֶ�������͵�ġ�\n");

        if( ob->query("no_get",1))
        return notify_fail("������������ֲ����ģ�\n");

        sp = (int)me->query_skill("begging",1)/20 + (int)me->query("kar");
               
        if( sp < 1 ) sp = 1;
        dp = (int)victim->query("kar");

        tell_object(me, "��װ�������Ͱ͵����ӣ���������" + victim->name() + "�߹�ȥ�����˫�֣���Ҫ"
                        + ob->query("unit") + ob->name() +"...\n\n");
        tell_object(victim, me->name() + "�����Ͱ͵����������߹���������֣�˵����" + RANK_D->query_respect(victim) + "���кã�����"
                        + ob->query("unit") + ob->name() + "�� ...��\n\n");
        message("vision", "ֻ��" + me->name() + "װ�������Ͱ͵����ӣ���������"
                + victim->name() + "�߹�ȥ��\n���˫�֣�˵����"
                + RANK_D->query_respect(victim) + "�����кð� ...\n\n", environment(me), ({ me, victim}) );

        me->set_temp("begging", 1);
        ob->set("no_get",1);
        call_out( "compelete_beg", 3, me, victim, ob, sp, dp);
        return 1;
}

private void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
        int amount, begging_level;
       int exp,pot;
        object ob1;
        object where;
        if (!environment(me))return notify_fail("�������²���beg�ˣ�\n");
        if (!me)  return notify_fail("���Ѿ������ˣ�\n");
        if (!victim)  return notify_fail("�Ǹ����Ѿ������ˣ�\n");
where= environment(me);
        me->delete_temp("begging");

        if( environment(victim) != environment(me) ) {
                tell_object(me, "̫��ϧ�ˣ���Ҫ���ֵ����Ѿ����ˡ�\n");
        if (!ob)  return notify_fail("���������Ѿ������ˣ�\n");
        ob->set("no_get",0);
                return;
        }

        if( living(victim) && (random(sp+dp) > dp) )
        {
        if (!ob)  return notify_fail("���������Ѿ������ˣ�\n");
                if ( ob->query("money_id") )
                {
                        amount = ob->query_amount();
                        if( amount < 5 )
                        {
                                tell_object(me, "���������߰ɣ���һ������Ѿ�û�ж�����ˮ��ե�ˡ�\n");
        ob->set("no_get",0);
                                return;
                        }

                        ob->set_amount(amount - amount/5);

                        ob1=new("/clone/money/" + ob->query("money_id"));
                        ob1->set_amount(amount/5);
                        ob1->move(me);
                        ob1->set("no_get",0);

                }
                else if( !ob->move(me) ) {
        if (!ob)  return notify_fail("���������Ѿ������ˣ�\n");
                        ob->move(where);
                        tell_object(me, "���ֵ�һ" + ob->query("unit") + ob->name()
                                + "�����Ƕ������̫���ˣ����ö��ڵ��¡�\n");
        ob->set("no_get",0);
                        return;
                }
               if (sizeof(all_inventory(me)) >= 40)
                {
                        tell_object(me, "�ۿ����Ҫ���֣���ϧ���ϵĶ�"
                                    "��̫�࣬ʵ���ò����ˡ�\n");
                        return;
                }


                tell_object(me, victim->name() + "��ͷ����һ�ᣬ�ֿ��˿��㣬ҡҡͷ��̾�˿�����������һ"
                                + ob->query("unit") + ob->name() + "��\n");
                tell_object(victim, "�㿴��" +  me->name() +"�Ŀ�������̾�˿�����������һ"
                                + ob->query("unit") + ob->name() + "��\n");
// �����ֹǱ�ܺͼ��ܴ���������
      begging_level = me->query_skill("begging", 1);
   if (!me) return notify_fail("���Ѿ������ˣ�\n");
      if ( (int)me->query("combat_exp") > (begging_level*begging_level*begging_level)/10)
         {
if (me->query_skill("begging"))
{
          me->improve_skill("begging", random(me->query("int")));
}
         }  else {
                 tell_object (me, "����㾭��ֵҲȥ�л������Ǳ�ȥ������!\n");
        ob->set("no_get",0);
                  }
      if (( (int)me->query("potential")-(int)me->query("learned_points") < 100))
                me->add("potential",1);
                me->add("combat_exp",1);
        ob->set("no_get",0);
                if( random(sp) > random(dp))
                        message("vision", "�㿴��" + victim->name() + "����" + me->name() + "������м��ҡҡͷ��"
                                + "������һ" + ob->query("unit")
                                + ob->name() + "��\n", environment(me), ({ me, victim }) );
                me->add("jing",-50);
        ob->set("no_get",0);
             //   me->add("eff_jing", -2);
		if (! me->is_busy())
		me->start_busy(6);
	if( userp(victim) && query_ip_name(victim)==query_ip_name(me) )
{
			message_vision(victim->name() + "��$Nһ�ۣ����ҹ�ϵ��ô�ã�����Ҫ�ҵĶ�����\n", me);

} else
{
exp=28+random(35);
pot=22+random(25);
  if( me->query("family/family_name") == "ؤ��" )
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

        }
        else
        {
                if( random(sp) < random(dp) ) {
                        message_vision(victim->name() + "�ݺݵص���$Nһ�ۣ��ȵ������� $N����һ������æŤͷ��������߿��ˡ�\n", me);
                        me->add("begger", 1);
                        me->add("jing",-20);
        ob->set("no_get",0);
                        me->add("eff_jing", -3);
me->start_busy(3);
                        return;
                }

                tell_object(me, victim->name() + "Ť��ͷȥ������������\n");
                tell_object(victim, "��Ť��ͷȥ����" + me->name() + "������\n");
                message("vision", victim->name() + "Ť��ͷȥ����" + me->name() +  "������\n",
                        environment(me), ({ me, victim }) );
if(ob)        ob->set("no_get",0);
                        me->add("eff_jing", -3);
                me->start_busy(3);

        }
}

int help(object me)
{
write(@HELP
ָ���ʽ : beg <ĳ��> from <ĳ��>

HELP
    );
    return 1;
}

