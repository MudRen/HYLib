//Cracked by Kafei
// /d/hangzhou/obj/jiasha.c
// by aln 4 / 98

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("��������", ({"jiasha", "jia", "sha"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��ո�µĴ�����ģ������������ɡ�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 10);
		  }

			if( !wizardp(this_player()) )
			{
				set("no_get", "�������������뿪�Ƕ���\n");
				set("no_drop", "�������������뿪�㡣\n");
			}
		  setup();
}

void init()
{
		  add_action("do_quan", "quan");
}

int do_quan(string arg)
{
		  object ob, me = this_player();

		  if( me->query("family/family_name") != "������" )
					 return notify_fail("�㲻�����ַ��ŵ��ӣ������������ǻ���\n");

        if( (int)me->query_skill("buddhism", 1) < 160 )
                return notify_fail("��ķ�ѧ��Ϊ��������ʹ�������ǻ���\n");

        if( me->is_fighting() || me->is_busy() )
	        return notify_fail("����æ�š�\n");

        if( me->query_temp("sl_quan") )
                return notify_fail("���Ѿ���Ȱ�������ˡ�\n");

        if( !arg )
                return notify_fail("��Ҫ��Ȱ˭��\n");

        if( !(ob = present(arg, environment(me))) )
                return notify_fail("���û����ҪȰ�����ˡ�\n");

        if( ob->query("race") != "����" )
                return notify_fail(ob->name() + "�������˻���\n");

        if( ob->query("shen") > -100000
        ||  (int)ob->query("combat_exp") < (int)me->query("combat_exp") )
                return notify_fail("����С���ˣ������ʦ�������ˡ�\n");

        if( ob->is_fighting() || ob->is_busy() )
	        return notify_fail(ob->name() + "��æ�š�\n");

		  if( userp(ob) )
					 return notify_fail("��Ȱ������ҡ�\n");

		  message_vision("$N��$n��Ȱ����ʩ���������أ��������ջ�ͷ�ǰ���\n", me, ob);

		  message_vision("$N��Ц������ٴȱ��ˣ����У���\n", ob);

		  if( (int)ob->query("eff_qi")*10 < (int)ob->query("max_qi")*9 ) {
					 ob->kill_ob(me);
					 return 1;
		  }

		  me->set_temp("sl_quan", 1);
		  me->start_busy(1);

		  if( me->query_temp("armor/cloth") == this_object() )
					 call_out("hitby", 1, me, ob, 7 + random(5));
		  else    call_out("hitby", 1, me, ob, 20 + random(10));
		  return 1;
}

void hitby(object me, object ob, int period)
{
		  object weapon;
        int bonus,pot,exp,bud;

        if( environment(me) != environment(ob) ) {
                me->delete_temp("sl_quan");
                tell_object(me, "���գ�" + ob->name() + "�Ѿ����ˡ�\n");
					 return;
		  }

		  if( me->is_fighting() ) {
					 me->delete_temp("sl_quan");
					 tell_object(me, "���Թ˲��ڣ�ֻ����ֹ�˹�Ȱ��\n");
					 return;
		  }

		  if( ob->is_fighting() ) {
					 me->delete_temp("sl_quan");
					 tell_object(me, ob->name() + "��æ�š�\n");
					 return;
		  }

		  if( (int)ob->query("eff_qi")*10 < (int)ob->query("max_qi")*5 ) {
					 me->delete_temp("sl_quan");
					 ob->kill_ob(me);
					 return;
		  }

		  //me->add_temp("apply/parry", -400);
		  //me->add_temp("apply/denfense", -400);
		  me->set_temp("apply/parry",me->query_temp("apply/parry",1)-90);
		  me->set_temp("apply/defense",me->query_temp("apply/defense",1)-90);
		  ob->set_temp("apply/damage",ob->query_temp("apply/damage",1)+90);
		  //ob->add_temp("apply/damage", (int)ob->query_skill("force")/2);
		  if( weapon = ob->query_temp("weapon") )
					 COMBAT_D->do_attack(ob, me, weapon);
		  else    COMBAT_D->do_attack(ob, me);
		  ob->set_temp("apply/damage",ob->query_temp("apply/damage",1)-90);
		  me->set_temp("apply/parry",me->query_temp("apply/parry",1)+90);
		  me->set_temp("apply/defense",me->query_temp("apply/defense",1)+90);
		  //me->add_temp("apply/defense", 400);
		  //me->add_temp("apply/parry", 400);
        

        if( (int)me->query("qi")*10 < (int)me->query("max_qi")*2 
        ||  (int)me->query("eff_qi") * 10 < (int)me->query("max_qi")*3 ) {
                me->delete_temp("sl_quan");
                message_vision("$N������Ц�����㻹���ٹ����°ɡ�\n", ob);
                return;
        }        

        period--;
        if( !period ) {
                me->delete_temp("sl_quan");
                message_vision("$N����л�������" + ob->query("name") + "�������壬�����磡\n", ob);
                message_vision("$N˵���ﳤ��ȥ��\n", ob);

                switch(ob->query("name")) {
		case "ŷ����" : bonus = 5; break;
                case "������" : bonus = 5; break;
                case "���ַ���" : bonus = 3; break;
                case "�Ħ��" : bonus = 3; break;
                case "Ѫ������" : bonus = 3; break;
                case "�鰲ͨ" : bonus = 5; break;
                default : bonus = 1; break;
                }

                bonus *= (int)ob->query("combat_exp") / 50000;
				bud = bonus/4+random(bonus/4);
                me->improve_skill("buddhism", bud);

				bonus = bonus*2/3;

				if(bonus<240)bonus=240;
				if(bonus>450)bonus=450;

				pot = bonus/4+random(bonus/4);
				if( me->query("potential",1) + pot > me->query("max_potential",1) ) 
				{
					pot = me->query("max_potential",1) - me->query("potential",1);
				}

				me->add("potential", pot);
				
				exp = bonus/3+random(bonus/4);
                me->add("combat_exp", exp);

                write_file("/log/test/ShaolinQuan", sprintf("%s��%sʱȰ%s��ͷ�ǰ���%s������%sǱ��and%sBuddhism\n", me->query("name"), ctime(time()), ob->query("name"), chinese_number(exp),chinese_number(pot),chinese_number(bud)));

                destruct(ob);
                return;
         }

         call_out("hitby", 1, me, ob, period);
}

                

