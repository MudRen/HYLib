// jiang-yaoting.c ��ҫͤ  ����������
// by llm 99/06
#include <ansi.h>
inherit NPC;
int do_unmarry(string arg);
int zou(object me);
int do_kill();
int do_chat();

void create()
{
	set_name("��ҫͤ", ({ "jiang yaoting", "jiang" }));
	set("title", "����֪��");
   set("gender", "����");
   set("age", 43);
   set("str", 20);
   set("dex", 20);
   set("long", "�����ǽ�ҫͤ����������֪���������ׯ����Ͻ�������ָ���������֮�¡�\n");
   set("combat_exp", 30000);
   set("shen_type", 0);
   set("attitude", "heroism");

   set_skill("unarmed", 50);
   set_skill("force", 50);
   set_skill("sword", 50);
   set_skill("dodge", 50);
   set_skill("parry", 50);
   set_temp("apply/attack", 150);
   set_temp("apply/defense", 150);
   set_temp("apply/armor", 150);
   set_temp("apply/damage", 150);

   set("neili", 500);
   set("max_neili", 500);
   set("jiali", 10);

   setup();
//   carry_object("/clone/weapon/gangjian")->wield();
   carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
   add_action("do_chat", "chat");
   add_action("do_chat","chat*");
   add_action("do_unmarry","unmarry");
   add_action("do_kill",({"kill","fight","hit","touxi"}));
}

int accept_object(object me, object ob)
{
   if (!ob->query("money_id"))
     	return notify_fail("��ҫͤ����ؿ�����һ�۵������ǲ��ǻ�ò��ͷ��ˣ����ñ�֪������Ц������\n");
  	if(ob->value() < 1000000)
	      return notify_fail("��ҫͤ������üͷ˵����������Բ��û�����ô�ţ�100 gold����һ��Ҳ����죡��\n");
	message_vision("��ҫͤ�ӹ�Ǯ���˵�����ðɣ�����������ɣ���\n",me);
	this_object()->set_temp("money",me->name());
  	return 1;
}

int do_chat()
{
   object me;
   me=this_player();

   message_vision(HIW "��֪����ɫһ��������ľһ�ĺȵ���������֮�ϣ���������������ѽ����\n"
   "���ڣ���������������Ӧ������ҫͤһָ$N�ȵ��������������ش��ʮ��壡��\n"NOR,me);
   call_out("zou",1,me);
   return 0;
}

int zou(object me)
{
   message_vision(HIW"һȺ���۳���ǰ�������ɷ�˵����$N�Ʒ��ڵأ�һ�����漴���ϡ���\n"NOR,me);
   tell_object(me,HIR"��շ��ֲ��ԣ���֫�Ѿ��������ڵأ�ֻ��һ�������ʹ����衭��\n"NOR);
	if((int)me->query("combat_exp")>10000
   	&&(int)me->query("qi")>20)
   {
		me->receive_damage("qi", 20);
		me->receive_wound("qi",  20);
   }
   else
      me->unconcious();
  	return 1;
}

int do_kill()
{
	object ob;
	int i;

	command("say �󵨣������ڹ����϶��䣬����ѽ��");
	message_vision("���ܵ���������Ⱥ���$N����������\n", this_player());

	for(i=0; i<4; i++)
   {
		if( objectp( ob = present("ya yi " + (i+1), environment(this_object())) ) )
			ob->kill_ob(this_player());
		else
      	this_object()->kill_ob(this_player());
	}
	return 1;
}

int do_unmarry(string arg)
{
	object me, obj,ob,*inv;
mapping my_skl;
string *skl_name;
int i,*level;

	me = this_player();
	if (me->is_busy())
		return notify_fail("��֪��üͷһ��˵�������㿴�����Լ��Ǹ�æ������\n");

	if( me->is_fighting() )
	{
		if( !this_object()->is_killing(me) )
			this_object()->kill_ob(me);
		return notify_fail("��ҫͤŭ�����գ���������������������������ȥ����ȥ��飡��\n");
	}

	if( this_object()->is_fighting() )
		return notify_fail("��֪��˵�������������£��ȱ��ٴ��������ﵷ�ҵ�����˵����\n");

	if( !living(this_object()) )
		return notify_fail("�㻹������취��֪�����˾��Ѱɡ�\n");

	if( !environment()||base_name(environment()) != query("startroom") )
		return notify_fail("֪������һ��˵��������ʲô���ȱ�����������˵����\n");

   if(me->query_temp("unmarry"))
   	return notify_fail("��ҫͤ�����������㣺�����ٲ��Ǹոհ����ǰ������������������ң�����\n");

	if( !mapp( me->query("couple") ) || !me->query("couple/have_couple") )
	{
		if ((string)me->query("gender") == "Ů��")
			say("��ҫͤ��һ���ȵ������󵨵󸾣������û���ɷ򣬻���ϷŪ���٣�����ѽ��������ʮ��壡��\n");
		else
			say("��ҫͤ��һ���ȵ������󵨵��������û�����ң�����ϷŪ���٣�����ѽ��������ʮ��壡��\n");
      call_out("zou",1,me);
      return 1;
	}
   if(!arg||arg!=(string)me->query("couple/couple_id"))
   	return notify_fail("��֪��������üͷ����Ҫ��˭��飿\n");
//   ob = new(LOGIN_OB);
//	ob->set("id",(string)me->query("couple/couple_id"));
//	if( !ob->restore() )
	seteuid(getuid());
	if( file_size(DATA_DIR + "login/" + arg[0..0] + "/" + arg + ".o")<0 )
   {
       message_vision("��ҫͤ����$N�ĳ�������ϸ�鿴�˰������ͷ��������Ȼ��İ����Ѿ������������Ҿ͸���\n"
       "�����������������ǮҲ����Ҫ���ˣ���Ȼ���ڰ��������˼�¼�󣬸����˹�ӡ����ʦү����\n"
       "��������һ�ݸ�����ׯ����Ȼ���ֶ�$N˵�������߰ɣ����Ѿ��ǵ����ˣ���\n",me);
		CHANNEL_D->do_channel(this_object(), "mudnews",
		sprintf( "���������飺����%s����ż�Ѿ�ȥ�������ǵĻ�����ϵ��Ȼ�����\n", me->name()));
		me->add("couple/unmarried", 1);
		me->set("couple/have_couple",0);
      return 1;
   }
	else if( !objectp(obj = present((string)me->query("couple/couple_id"), environment(me)))
                 || !find_player(me->query("couple/couple_id")) )
		return notify_fail("��֪�������ؿ��˿����������İ������ڲ��ڳ���Ҫ����һ�������ܰ���顣��\n");

   if(query_temp("money")!=me->name()
   	&&query_temp("money")!=obj->name())
   	return notify_fail("��֪�����������ӣ�������������100 gold�㻹û����ûǮ�ͻ�ȥ�պ��Ź����ӣ���Ҫ�������٣�\n");

	if( (object)obj->query_temp("pending/unmarry")!=me )
	{
		me->set_temp("pending/unmarry", obj);
		message_vision(MAG "\n$N���˿�$n��̾һ�����������հհա������ǻ��Ǻþۺ�ɢ�ɣ�?��\n"
			"��ҫͤ�����۾�����$n������Ը��Ը������أ�˵����������Ϊ����������\n"NOR,me,obj);
      tell_object(obj,"�����ͬ����飬����Ҳ��"+me->name()+ "("+(string)me->query("id")+
                       	")"+ "��һ�� unmarry "+(string)me->query("id")+"  ��ָ�\n");
		write(MAG "���������ȴ�����İ��µĻش�...\n" NOR);
		return 1;
	}
	message_vision(MAG "\n$N����$n����һ��˵�������������񣬼�Ȼ��Ե�����Ǿ͸��߸���·�ɡ���\n\n"NOR, me,obj);
   me->set_temp("unmarry",1);
   obj->set_temp("unmarry",1);
	message_vision(HIY "��ҫͤ���˿����ͷ˵������$N��$n����Ȼ���Ƕ�ͬ����飬�Ǳ���Ҳ�͸����ǰ��ˣ���\n"
   	"˵�꣬����Ե�������صػ�ȥ���������֡�\n" NOR, obj, me);
	CHANNEL_D->do_channel(this_object(), "mudnews",
	sprintf( "���������У��ӽ�����%s��%s�Ļ�����ϵ�����\n", me->name(), obj->name()));

	me->add("couple/unmarried", 1);
	me->set("couple/have_couple",0);
        my_skl=me->query_skills();
        if(mapp(my_skl)) {
        		skl_name = keys(my_skl);
        		level=values(my_skl);
        		for (i=0;i<sizeof(skl_name);i++)
{
if (level[i]>3)
        		me->set_skill(skl_name[i],level[i]-2);
}
                  }

	obj->add("couple/unmarried", 1);
	obj->set("couple/have_couple",0);
//        my_skl=obj->query_skills();
//        if(mapp(my_skl)) {
//        		skl_name = keys(my_skl);
//        		level=values(my_skl);
//        		for (i=0;i<sizeof(skl_name);i++)
//{
//if (level[i]>3)
//        		obj->set_skill(skl_name[i],level[i]-2);
//}
//                  }

	return 1;
}
