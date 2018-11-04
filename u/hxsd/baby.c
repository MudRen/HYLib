// baby.c
#include <ansi.h>
#include <combat.h>
inherit NPC;

void try_move();

void create()
{
        set_name("����", ({"xiao baobao","baby"}) );
if (random(10)>5)
{
        set("gender", "Ů��");
}
else {
        set("gender", "����");
}

        set("age", 1);
        set_temp("no_kill",1);
        set("attitude", "friendly");
        set("long","�Ա������������nie,shua������������\n");
        set("combat_exp", 1);
        set("str",3);
        set("parents",({"dad","mom"}));
   
        set("chat_chance", 2);
        set("chat_msg", ({
           (: random_move :)
        }));

        set("is_baby",1);
        // to allow the identification of baby. by mon.

        setup();
}

void init()
{
	object ob;
	ob = this_object();
       add_action("do_kill",({"kill","fight","hit","steal"}));
  add_action ("do_setid", "setid");
  add_action ("do_setname", "setname");
  add_action ("do_nie", "nie");
  add_action ("do_shua", "shua");
       add_action("do_get","get");
       add_action("do_drop","drop");
	add_action("do_shape", "qk");
	add_action("do_cun", "cundang");
	add_action("do_teach", "jiao");   
       remove_call_out("try_move");
       call_out("try_move",1);
}

void try_move()
{
      if(random(20)==0)
      {
             remove_call_out("random_move");
             call_out("random_move",5);
      }
}

int do_drop(string arg)
{
      object me=this_object(),who=this_player(),env;
      if(!arg) return 0;
      env = environment(who);
      if(present(arg,who)!=me) return 0;
      if(me->move(env))
      {
             message_vision("$N��$n�ӻ������������\n",who,me);
             return 1;
      }
      return 0;
}

int do_get(string arg)
{
      object me=this_object(),who=this_player(),env;

      if(!arg) return 0;
      env = environment(who);
      if(present(arg,env)!=me) return 0;
      if(member_array(who->query("id"),
             me->query("parents"))>-1)
      {
             if(me->move(who))
             {
                   message_vision("$N��������$n����������§�ڻ��\n",who,me);
             }
             else
             {
                   message_vision("$N������һ��ȴû��$n��������С�һ�ó��ģ�\n",who,me);
             }
      }
      else
      {
             message_vision("$N������$n�쿪˫�֣�$nȴһ���������ˣ�����\n",who,me);
      }
      return 1;
}

int do_kill(string arg)
{       
      object me,who;
      string name,verb,what,obj;
      if (!arg) return 0;
      verb=query_verb();
      me=this_player();
   
      if(verb=="steal")
      {
             if(sscanf(arg, "%s from %s", what, obj)!=2 ) 
             return 0;
      }
      else obj=arg;

      if(!objectp(who=present(obj,environment(me))) 
            || !living(who)) return 0;
//    if(who->query("is_baby")) {
      if(who==this_object())
      {
             switch(verb)
             {
                    case "kill":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"ƴ���ؿ����������������������"+
                             me->query("name")+"Ҫɱ�ң����������ѽ��\n");
                         break;
                    case "hit":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"������������������������"+
                             me->query("name")+"�۸��ң����������ѽ��\n");
                         break;
                    case "fight":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"�����������������������"+
                             me->query("name")+"Ҫ���ҵ��ǳԣ����������ѽ��\n");
                         break;
                    case "steal":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"�����������������������"+
                             me->query("name")+"Ҫ͵���ҵ��ǣ�\n");
                         break;
                    case "beg":
//         command("chat* "+
                         tell_object(environment(this_object()),
                         who->query("name")+"С��һ������������������������"+
                             me->query("name")+"Ҫƭ�ҵ��ǳԣ�\n");
                         break;
             }
      }
      command(verb);
      return 0;
}

void relay_emote(object ob, string verb)
{
      if( !userp(ob) ) return;

      switch(verb)
      {
            case "kick":
                 command("say �������������"  + ob->query("name") + "����Ү��");
                 command("kick " + ob->query("id"));
                 break;
            case "slap":
                 command("say �������������"  + ob->query("name") +
                 "����Ү����ʹ����������");
                 command("slap " + ob->query("id"));
                 break;
            case "hit":
                 command("pain " + ob->query("id"));
                 break;
            case "bite":
                 command("face " + ob->query("id"));
                 break;  
            case "papaya":
                 command("angry");
                 break;  
      }
}

void relay_whisper(object me, string msg)
{
      if (member_array(me->query("id"),query("parents"))==-1)
      {
            message_vision((string)this_object()->query("name")
                        + "�ɻ�ؿ���$N��\n", me);
            return;
      }

      //note, do not allow the order contain "chat", "tell"...
      //may need disable more later...
      if( strsrch(msg, "chat") != -1 ||
          strsrch(msg, "tell") != -1 ||
          strsrch(msg, "follow") != -1 ||
          strsrch(msg, "apprentice") != -1 ||
          strsrch(msg, "recruit") != -1 )
            return;

      if (msg)
      {
            remove_call_out ("relaying");
            call_out ("relaying", 1+random(3), msg);
      }
}

void relaying (string msg)
{
//execute the order.
      command (msg);
}

int do_setid (string arg)
{
  object me = this_player();
  string name = this_object()->query("name");

  if (!wizardp(me))
    return 0;
  this_object()->set_name(name, ({ arg }) );
  return 1;
}

int do_setname (string arg)
{
  object me = this_player();

  if (!wizardp(me))
    return 0;

this_object()->set("name"," "+ arg+" ");
//  this_object()->set("name",arg);
  this_object()->set("long","һ"+this_object()->query("unit")+arg+"��\n");
  return 1;
}

int do_setunit (string arg)
{
  object me = this_player();

  if (!wizardp(me))
    return 0;

  this_object()->set("unit",arg);
  this_object()->set("long","һ"+arg+this_object()->query("name")+"��\n");
  return 1;
}

string rdm(string *strs)
{
  return strs[random(sizeof(strs))];
}

int do_nie (string arg)
{
  string *dos = ({
    "����ָ����һ��",
    "��������һ��",
    "С�ĵ���һ��",
    "��һ��",
    "������һ��",
    "����",
    "����ָ��һ��",
  });

  string *parts = ({
    "�Դ�",
    "ͷ��",
    "����",
    "������",
    "����",
    "С�촽",
    "����",
    "ü��",
    "����ë",
    "����",
    "С�Ǽ�",
    "�°�",
    "С����",
    "��",
    "�첲",
    "��",
    "��",
    "�Ƕ�",
    "Сƨƨ",
  });

  string *actions = ({
    "�ſ�С��֨֨�ؽ���������",
    "�ſ��찡Ӵ��һ����",
    "�����ѽѽ�г���������",
    "�������۾���ર�વ�գ�˼��¡�",
    "˯�����ʵ���������һ�Դ��۾���",
    "�����۾���������غ����۾�˯���ˡ�",
    "ҡ��ҡ˶����Դ���",
    "���������Ŭ��̧����Դ���",
    "����ص���Դ���",
    "���Ŵ��۾�����$N��",
    "�����ؿ���$N���ԳԵ�Ц��������",
    "�����ֵ���ָ�ŵ����һ��˱��һ�߿���$N��",
    "���Դ�������һת���˿�����̧ͷ����$N��",
    "���ߵذ��Դ���$N����һ�ꡣ",
    "����ذѴ��Դ�����$N���ϡ�",
    "����һ���¶�ü��",
    "С��ͷ���������һ���ͷ��",
    "���˵ذ��۾��г�һ���졣",
    "�ֿ�С���۵�һ�����˳�����",
    "�ڳ�һ���ɰ���С�������",
    "�ſ�С��޵ô�����������",
    "�����۾����ſ�С��Ц�˳�����",
    "����һЦ��",
    "ЦѽЦѽЦѽ��",
    "ѽѽӴӴ�س��˼��䡣",
    "���˵س������������డ��������",
    "����ҡ������˯˯�ɣ��Թ�Ү����",
    "�����˵�������С�졣",
    "���������������С�����",
    "����С����۶�һ��Ť��ͷȥ�������ˡ�",
    "��С�־�ס$N����ڡ�",
    "һ�Ѿ�ס$N���·��������š�",
    "��ס$N�����۰Ͱ͵�����$N��",
    "�������С�Ⱥ������˼��¡�",
    "̧��һ��С������$N�����ϡ�",
    "���˵��Ĵ�������С�ȶ���",
    "Ť��Ť��֫��",
    "���˾�Сƨƨ��",
    "��Сƨƨ��$Nһ�ᡣ",
    "Ц��������",
    "������Ц����ͣ��",
    "§��$N�Ĳ���Ц��������",
    "�����һЦ�����尢�̣���Ҫ����������",
    "������ʣ������������ò���ѽ��",
    "��$N��Ҫ���������������ǲ��Ǹ�ϲ����ѽ��",
    "ͻȻ����˵���ף��Ǹ�������С���ӣ�����ôû���أ�",
    "˵��Ӵ������ͷ���泤�����ڱ�������������Ү��",
    "�ʵ���С������ʲôʱ���ܳ��ɴ󱦱��ϱ�����",
    "˵�������̣�Ҫ��Ҫ���ҳ�֧�裿",
    "˵���������볪֧���裬��һ֧�أ����벻������֧������ġ�",
    "�������˵�����尢�̣����Ǹ���õ�С�Թ�Ү��",
    "һ��һ���˵������Թ�Ү�����尢��ֻϲ����һ��С�ԹԺ���",
    "���������˵������С�Թԣ�С�Թ����ҡ�",
    "ϸ��ϸ����˵��С�Թ��ҡ����������Ү��",
    "˵�����������һ�����Ǻò��ã�",
    "˵�����尢���ܱ�ħ���𣿱���������ò��ã�",
  });

  string str1 = "$N"+rdm(dos)+"$n��"+rdm(parts)+"��\n";  
  string str2 = "$n"+rdm(actions)+"\n";
  
  if (arg != this_object()->query("id"))
    return 0;

  remove_call_out ("delayed_action");
  call_out ("delayed_action",1,str1,this_player(),this_object());
  remove_call_out ("delayed_reaction");
  call_out ("delayed_reaction",3,str2,this_player(),this_object());
  return 1;
}

int do_shua (string arg)
{
  object me = this_object();
  object who;
  string my_name = me->query("name");
  string *dos = ({
    "�ɿ�ش�$N����������������$n��",
    "��$N���ϻ��������ڵ�$n��",
    "��$N����ʹ����$n����һ��������$n��",
    "��$N���ͷ��һת�����$n��",
    "���������$n��",
    "�������˵�$n��",
    "�������رĵ�$n��",
    "һ�������˵�$n��",
    "����$n��",
    "����һ����Ծ��$n��",
    "һ��С����Ծ��$n��",
    "����һ������վ��$n��",
    "���ɵ�һ����ץ��$n��",
    "�����ץ��$n��",
  });

  string *parts = ({
    "������",
    "������",
    "��ͷ��",
    "ͺ��",
    "ˮ����",
    "������",
    "����",
    "������",
    "���촽",
    "�ֿ������",
    "�ʶ���",
    "����",
    "�������",
    "�����",
    "���°�",
    "б����",
    "�Ჱ��",
    "�ݺ��",
    "�����",
    "����",
    "��Ĵָ",
    "����",
    "����",
    "����",
    "�첲��",
    "���Ź�",
    "С��",
    "����",
    "����",
    "��������",
    "��Ȧ��",
    "������",
    "ˮͰ��",
    "�Ϲ���",
    "ˮ����",
    "ˮ�ܲ���",
    "�黨��",
    "������",
    "�ź��",
    "���ű�",
    "���ֺ",
    "ϸ����",
    "���Ƥ",
    "ơ�Ʒʶ�",
    "���Ƥ",
    "�ձ�",
    "����",
    "�μ�",
  });

  string *actions = ({
    "��������Ѹ������һС̲��",
    "����Сˮǹ�Ϳ�һ����",
    "����һС�ڡ�",
    "�³�һС��ճճ�Ŀ���������",
    "�ſھ����˼��ڡ�",
    "��$n�����ȥ������",
    "�ſ�С��ҧ��һ�ڡ�",
    "�ſ�С��ҧס$n�������š�",
    "ҧ��һС���⡣",
    "ҧ��һ������⡣",
    "ҧ��$n���ض���޵����",
    "ҧ�����ź���ӡ����",
    "ҧ��һ�����Ѫ�ϰ̡�",
    "����һ��ë��",
    "����һ����Ƥ��",
    "��סһ��ϸë���š�",
    "Ӳ�ǳ���һ��Ѫ�Һ�«��",
    "��ર��ʹ�����˼�ȭ��",
    "����һ�������ס�",
    "�������˼��¡�",
    "�ߵ�$n������й��",
    "���һ������Ҫ����",
    "�ߵ�$nֱ�����ۡ�",
    "�ô��Դ����һײ��",
    "��Сָ���������廨������",
    "ʹ����ץ�����Ѫ�ۡ�",
    "ץ���崮ˮ�ݡ�",
    "���˫��������һ����",
    "ҧ���гݵ���ס$n�����С�",
    "����������ô�һ���׿顣",
    "ק������ǧ��",
    "žž���ҿ�������ʮ���¡�",
    "���˸�����졣",
    "����������������������",
    "�ӳ�һ��Ƭ��ͷ���ӡ�",
    "��С��ָ�ٳ�һС���塣",
    "����ָ�ٳ�һɳ����",
    "�ͳ�һ���̡�",
    "ץ��һ��Ƭ�ഺ��������",
  });

  string *returns = ({
    "Ȼ���ܻ�$N���ϡ�",
    "Ȼ�����ĵػص�$N���С�",
    "�ٻ�ͷһ������������$N���ϡ�",
    "������Ծ�ص�$N���С�",
    "�ٻ�ͷһ����Ծ��$N���ϡ�",
    "Ȼ����˵ػص�$N���С�",
    "Ȼ���������$N���ϡ�",
    "Ȼ��ʮ����������$N���С�",
    "Ȼ���˷ܵرĻ�$N���ϡ�",
    "Ȼ����ϲ����رĻ�$N���С�",
  });

  string str1 = my_name+rdm(dos)+rdm(parts)+"�ϣ�"+rdm(actions)+"\n";
  
  if (! arg)
    return 0;

  who = present(arg,environment(this_player()));
  if (! who)
    return notify_fail ("ˣ˭��\n");

  message_vision ("$N��"+my_name+
                  "ʹ��һ����ɫ��Ȼ���������µؿ���$nһ�ۡ�\n",
                  this_player(),who);
  remove_call_out ("delayed_action");
  call_out ("delayed_action",3,str1,this_player(),who);
  remove_call_out ("delayed_reaction");
  call_out ("delayed_reaction",4,rdm(returns)+"\n",
            this_player(),who);
  return 1;
}

void delayed_action (string str, object ob1, object ob2)
{
  message_vision (str,ob1,ob2);
}

void delayed_reaction (string str, object ob1, object ob2)
{
  message_vision (str,ob1,ob2);
}





string query_save_file()
{
	string id;

	id = query("momid");
	if( !stringp(id) ) return 0;
	return sprintf("/data/baby/%c/%s", id[0], id+".c");
}

int save()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}

int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
                return restore_object(file);
        return 0;
}

void die()
{	
	int i;
	object owner, *enemy;
	int jing,qi,exp;

	exp = (int) query("combat_exp");
	jing = (int) query("max_jing");
	qi = (int) query("max_qi");

	if(!environment()->query("no_death_penalty"))
		set("combat_exp", exp/10 * 9);
	set("eff_qi", qi);
	set("eff_jing", jing);
	set("qi", qi);
	set("jing", jing);

	save();	
	::die();
}
string status_color(int current, int max)
{
        int percent;


        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}

int do_shape(string arg)
{
{	mapping my;
	string shape;
	int at_pt,pa_pt,do_pt;
if (!arg)
return notify_fail("��Ҫ��˭��״̬��\n");
if (arg !=query("id"))
return notify_fail("��Ҫ��˭��״̬��\n");
	my = query_entire_dbase();
	 printf(HIC"��"HIY"������������������������������������������������������������"HIC"��\n"NOR);
printf(HIC"������"NOR"%s%3d/ %3d %s(%3d%%)   "HIC"��Ѫ��"NOR"%s%3d/ %3d %s(%3d%%)\n",
                status_color(my["jing"], my["eff_jing"]), my["jing"],my["eff_jing"],
                status_color(my["eff_jing"], my["max_jing"]),     my["eff_jing"] * 100 / my["max_jing"],
                status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
                status_color(my["eff_qi"], my["max_qi"]),     my["eff_qi"] * 100 / my["max_qi"]            
	);		
	printf(HIW"������ "HIG"%s"NOR"\t\t"HIW"���飺 "HIG"%d"NOR"\t\t"HIW"ɱ���� "HIG"%d"NOR"\n"NOR,
	my["name"], my["combat_exp"],my["bellicosity"]
	);
        printf(HIY"���ԣ� "HIG"%d"NOR"\t\t"HIY"���ǣ� "HIG"%d"NOR"\t\t"HIY"��ò�� "HIG"%d"NOR"\n"NOR,
        query_int(), query_con(),query_per()
        );
        printf(HIY"���� "HIG"%d"NOR"\t\t"HIY"������ "HIG"%d"NOR"\t\t"HIY"��Ե�� "HIG"%d"NOR"\n"NOR,
        query_dex(), query_str(),query_kar()
        );
        printf(HIY"������ "HIG"%d"NOR"\t\t"HIY"�������ޣ� "HIG"%d"NOR"\t\t\n"NOR,
        query("neili"), query("max_neili")
        );

        at_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_ATTACK);
        pa_pt= COMBAT_D->skill_power(this_object(), "parry", SKILL_USAGE_DEFENSE);
        do_pt= COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);
        printf(HIR"�������� %d\t"NOR+HIR"�������� %d\t\n"NOR,
        at_pt+1, pa_pt/2+do_pt/2+1
        );
	printf("/cmds/skill/skills"->pet_skill(this_object()));
	 printf(HIC"��"HIY"������������������������������������������������������������"HIC"��\n"NOR);
 return 1;
}

int do_cun(string arg)
{
	object me, ob;
	me = this_player();
	ob = this_object();

        if ( me->is_busy() )
                return notify_fail("����һ��������û����ɣ�\n");

        if ( me->is_fighting() )
                return notify_fail("�㻹��ר����ս�ɣ�\n");

 	if ( ! (me->query("id") == ob->query("momid") || me->query("id") == ob->query("popid")) )
		return notify_fail("ʲô��\n");

	if ( ob->query_temp("saved"))
		return notify_fail("���������к�ϵͳӲ�̽��������Ժ����ԡ�\n");
	ob->set_temp("saved", 1);
	ob->save();
me->start_busy(8);
	write("���ӵ�����Ѿ�������ϡ�\n");
	return 1;
}

int do_teach(string arg)
{
	object me, ob;
	int gin_cost,amount, myskill, itskill;
	string student, skill;

	me = this_player();
	ob = this_object();

        if ( me->is_busy()) return notify_fail("��������æ���ء�\n");

        if ( me->is_fighting() ) return notify_fail("�㲻����ս���н���֪ʶ��\n");

	if ( !arg || (sscanf(arg, "%s about %s", student, skill) != 2) )
		return notify_fail("ָ���ʽ��jiao <ĳ��> about <����>\n");

	if ( student != ob->query("id") ) return notify_fail("��Ҫ��˭��\n");

	if ( !myskill = me->query_skill(skill, 1)) return notify_fail("���������󻹲����أ�\n");

	if ( me->query("id") != ob->query("momid") && me->query("id") != ob->query("popid") )
		return notify_fail ("�Լ��ĺ����Լ��̣��㲻�õ����������\n");

	if ( !living(ob) ) return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");

	if ( ! ob->query("is_baby") ) return notify_fail("�˼�Ҳ��ʦ�����е��������̣�\n");

	itskill = ob->query_skill(skill, 1);

	if(myskill <= itskill) return notify_fail( ob->name()+"�Գ�Ц��Ŀ�������㡣\n");

	if( (int)me->query("potential") < 1 ) return notify_fail("���Ǳ�ܲ�����\n");

	gin_cost = (int)ob->query_int();

	if( (int)me->query("jing") < gin_cost) return notify_fail("����Ȼ̫����û�а취�̣�\n");

	me->receive_damage("jing", gin_cost);
	amount = (int)me->query("int") + (int)ob->query("int");

	message_vision(sprintf("$N�����䷳�ؽ�$n��%s����\n", to_chinese(skill)), me, ob);

	if( (int)ob->query_temp("is_hungry") > 10+random(5) || ob->query("is_hungry") ) {
		ob->set("is_hungry", 1);
		ob->delete_temp("is_hungry");
		return notify_fail ("���Ӵ�޴��֣������Ƕ���\n");
	}
	if( random(30) < ob->query("tol") ) {
		if (ob->query("age") < 5)
			message_vision("$n���۵ش��������$N˵ʲôҲ�岻ס��\n", me, ob);
		else
			message_vision("$n��޴��֣�˵ʲôҲ����$N����\n", me, ob);
	}
	else {
		ob->add_skill(skill, amount);
		ob->add( "combat_exp", amount/20+random(amount/20) );
		message_vision(sprintf("$N�ƺ����ѧ����һЩ��%s����\n", to_chinese(skill)), ob);
		me->add("combat_exp", 1);
		me->start_busy(1);
		ob->add_temp("is_hungry", 1);
	}
	return 1;
}

varargs void add_skill(string skill, int amount)
{
	if( !find_object(SKILL_D(skill)) && file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) ) skills = ([]);
	if( undefinedp(skills[skill]) ) skills[skill] = 0;

	if( !amount ) amount = 1;

	if( !mapp(learned) ) learned = ([ skill : amount ]);
	else (int)learned[skill] += amount;

	if( learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) ) {
		skills[skill]++;
		learned[skill] = 0;
		this_object()->set_skill(skill, skills[skill]+1);
	}
}

int accept_object(object me, object obj)
{
	object ob;
	ob = this_object();
	if ( me->query("id") != ob->query("momid") && me->query("id") != ob->query("popid") )
		return notify_fail ("�˼Ҹ�ĸ���չ��Լ��ĺ�������\n");

	if( ! obj->wear() )  {
		command("cry");
		return 0;
	}
        call_out ("baby_wear", 0, me, obj);
        return 1;
}

void baby_wear(object me, object obj)
{
if (!me) return; if (!obj) return;
	message_vision(sprintf("$N���Լ��ĺ��Ӵ���һ%s%s��\n", obj->query("unit"), obj->query("name")), me);
	obj->move(this_object());
	obj->wear();
}
