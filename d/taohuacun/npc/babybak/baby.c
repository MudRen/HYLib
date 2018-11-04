// baby.c

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
       add_action("do_kill",({"kill","fight","hit","steal"}));
  add_action ("do_setid", "setid");
  add_action ("do_setname", "setname");
  add_action ("do_nie", "nie");
  add_action ("do_shua", "shua");
       add_action("do_get","get");
       add_action("do_drop","drop");
       /* follow is very costly to execute. 5/6/98 mon.
       if(member_array(this_player()->query("id"),
             this_object()->query("parents"))>-1)
       {
             this_object()->set_leader(this_player());
       }
   */
   
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
