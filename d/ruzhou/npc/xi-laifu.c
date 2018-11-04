// NPC: /d/ruzhou/npc/xi-laifu.c  ��ϲ����ֵ�ϲ�����ϰ�
// llm 99/07/09

#include <ansi.h>

inherit NPC;
int ask_party();
void start_party(object ob,object me);
int do_start();
int do_serve();
void finish_party(object me,object ob);
int give_money(object me,object ob);
int do_kill(string arg);
int do_exert(string arg);
int do_steal(string arg);

void create()
{
	set_name("ϲ����",({"xi laifu","xi","laifu" }));
   set("title", "ӭ��¥�ϰ�");
   set("age", 42);
   set("gender", "����");
   set("attitude", "friendly");
   set("combat_exp", 50000);
   set_skill("unarmed", 100);
   set_skill("dodge", 100);
   set_skill("parry", 100);
   set("per", 20);

	set("inquiry", ([
		"name": "ϲ�����Ǻ�Ц������С�������е㸣������ϲ������������������ϰ塣\n",
		"here": "ϲ����ҡͷ���Ե�˵��������ӭ��¥���Ƿ�Բ��ʮ�����¥����ϲ�绹��Ҫ�����������\n",
		"��" : (: ask_party :),
		"ϲ��" : (: ask_party :),
		"ϯ" : (: ask_party :),
		"��ϯ" : (: ask_party :),
		"ϲ��" : (: ask_party :),
		"����" : (: ask_party :),
		"party" : (: ask_party :),
		]) );
   setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
   object me=this_player();
   ::init();
	if( interactive(me) && !is_fighting() )
   {
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
   add_action("do_serve", "kaixi");
   add_action("do_finish", "jieshu");
   add_action("do_start", "kaishi");
   add_action("do_kill", ({"kill","fight","hit","perform"}));
   add_action("do_steal", "steal");
   add_action("do_exert", "exert");
}

int greeting(object me)
{

   if( !me || environment(me) != environment() ) return 0;

   if(me->query_temp("married_party") )//����
   {
   	write("ϲ�ϰ���㹰�ֵ�����ϲ�粼�õò���ˣ��ȿ���������������ϲ������ˣ���\n");
   }
   else if(!query_temp("party_finish"))//ϲ��δ��������ϲ�Ƶ���
   {
      write("ϲ�ϰ���ͷ����Ӵ��������ϲ��ѽ�����˵�������Ҵ��գ������Ҿ��С���\n");
   }
	else
   {
   	write("ϲ�ϰ�һ���֣������Ժã����ߣ���\n");
   }
   return 1;
}

int accept_object(object me, object ob)
{
   int i;
	if(query_temp("party_finish"))
   	return notify_fail("ϲ�ϰ�Ǻ�һЦ�����������ˣ�ϲ���Ѿ������ˣ�������ֱ�Ӹ����˰ɣ���\n");
   if (!ob->query("money_id"))
     	return notify_fail("ϲ�ϰ�������üͷ���������Ͳ�ʱ���Ͷ����ˣ���ϲ�ƻ��Ǹ��ֽ�ĺã���\n");
   if(me->query_temp("marry_patty"))
   	return notify_fail("ϲ�ϰ�һ㶣���Ц�������Լ����Լ�����Ҳû�������Ա��˳��ŵ��°ɣ���\n");
   i = ob->value();
   CHANNEL_D->do_channel(this_object(), "chat",
	   sprintf("%s����%s��%s�»��ϲ�����Ϻ���"+MONEY_D->price_str(i)+"��\n",me->name(),query("name1"),query("name2")));
	add("chat_amount",1);//��ˮ��Զ����
	add("money",i);//��¼�����������
   return 1;
}

int ask_party()
{
   object me,ob,wife;
   ob=this_object();
   me=this_player();
   if( me->query_temp("host_of_party") )
   {
   	message_vision("$N��$n˵��������ϲ�粻�����ڿ����𣿡�\n", ob, me);
   	return 1;
   }
   if( (string)me->query("gender")=="Ů��" )
   {
     message_vision("$NЦ�Ŷ�$n˵������ý���������ɵ��������ⶩ��ϯ�����ǽ�����ɷ����ʰɣ���\n", ob,me);
     return 1;
   }
	if( !me->query_temp("married_party") )
   {
   	message_vision("$N���˷��ʱ�����$n���ɵ��ʵ�����ý�ź���û���������������ϲ�ۣ��᲻�����ˣ���\n", ob,me);
   	return 1;
   }
   if( !objectp(wife=present(me->query("couple/couple_id"), environment(me))) )
   {
   	message_vision("$N��$n˵�������Ӷ�û������ϲ����ô����\n", ob,me);
      return 1;
   }
   if( ob->query_temp("ready_to_party") )
   {
   	message_vision("$N��$n������˼��˵������������һϯ�أ�Ҫ�������������ɣ�\n",ob,me);
   	return 1;
   }
   if( (string)environment(ob)->query("short")!="ϲ����" )
   {
   	message_vision("$N��$nΪ�ѵ�˵�����Բ��𣬵��һص�׼������˵�ɣ���\n",ob,me);
   	return 1;
   }
   if( me->query_temp("ready_to_ask") )
   {
   	message_vision("$N��$n���ͷ���˵���������Ƕ�˵��������ô�ʸ�û�꣡��\n",ob,me);
   	return 1;
   }
   me->set_temp("ready_to_ask",1);//�����ʹ��˵ļǺ�
   ob->set_temp("ready_to_party",1);//�ϰ忪ʼ�Ǻ�
   me->set_temp("host_of_party",1);//���ɵļǺ�
   me->delete_temp("married_party");
   call_out("start_party",1,ob,me);
}

void start_party(object ob,object me)
{
   command("chat* "+name()+"һ���ֵ���������һ��ֵǧ�𣬾Ʋ���������������ӭ��¥���ҵ�Ϊ" + me->query("name") +
		"\n��ϲ�磬��ӭ��λǰ��������\n\n");
   message_vision("ϲ�ϰ�ת���ֶ�$NС�����˼��䡣\n",me);
   message_vision("��Ҫ��ʼ�������� kaishi������뿪ϯ�������� kaixi��\n"
   "��ҳԱ��ˣ������˾Ϳ��Խ�����(jieshu)��");
   me->delete_temp("ready_to_ask");
   me->set_temp("ready_to_party", 1);//����׼����ʼ�Ǻ�
}

int do_start()
{
   object me,ob,usr,obj,*list;
   int i;
   me = this_player();
	ob = this_object();

   if( !me->query_temp("host_of_party") )
     return notify_fail(name()+"����˵�������ֲ������ɹ٣���ʲô������\n");
   if( !ob->query_temp("ready_to_party") )
     return notify_fail(name()+"����˵������ʼʲôѽ��������û�˰���磡��\n");
   if( me->query_temp("party_start_already") )
     return notify_fail(name()+"Ц�Ǻǵض���˵�����㿴�ⲻ���Ѿ���ʼ�����\n");

   message_vision("$N��$n���ͷ˵����ϲ�ϰ壬ϲ����Կ�ʼ�ˣ���\n\n"
		"$n���̴������ţ����������ϡ���ϲ�����ơ�����\n\n",me,ob);
   me->set_temp("party_start_already", 1);//�����Ѿ���ʼ�Ǻ�
   me->delete_temp("ready_to_party");
   tell_room( environment(ob), HIY"ϲ�ϰ�����һ�ӣ����������������̴������š�����ϲ�֡�\n"NOR);

   list = all_inventory(environment(me));
   i = sizeof(list);
   while (i--)
   {
       usr= list[i];
       if( obj=new(__DIR__"obj/xijiu"))
       obj->move(usr);
   }
   tell_room(environment(usr), "\n�������߳�һ��Ư���Ļ�����Ů�������ߵ�ÿ������ǰ��\n"
		"������Ů�ݸ���һ������ϲ�Ƶ���յ���߿���ȥ��\n");
   call_out("finish_party", 500, me,ob);
   return 1;
}

int do_serve()
{
   object ob=this_object();
   object me=this_player();
   object food;
   if( !me->query_temp("host_of_party") )
     return notify_fail(name()+"б�۵�����һ�۵���������û˵��������ʲô������\n");
   if( !me->query_temp("party_start_already") )
     return notify_fail(name()+"����Ц˵������û�����ҿ�ʼ(kaishi)������ô�ÿ�ϯ����\n");

   message_vision("$N���������ţ��ϲˣ��ϲˣ�\n", me);

   tell_room(environment(me), "���������������С��ƴ�������������һ������ζ�������̰���������\n");
   if(food=new(__DIR__"obj/jiuyan"))
        food->move(environment(me));
   return 1;
}

int do_finish()
{
   object ob=this_object();
   object me=this_player();

   if( !me->query_temp("host_of_party") )
     return notify_fail(name()+"������ص�����һ�ۣ��������ģ��������²�Ҫ��˵������\n");

   if( !me->query_temp("party_start_already") )
     return notify_fail(name()+"�Ǻ�Ц������ϲ�۲����Ѿ��������𣡡�\n");
   message_vision("$N��$n˵���������˳Եö�����ʮ�ָ�лϲ�ϰ�İ��ţ���\n", me, ob);
   remove_call_out("finish_party");
   call_out("finish_party", 2, me,ob);
   return 1;
}

void finish_party(object me,object ob)
{
   int i;
   object *list,ob1,ob2,usr;

   message_vision(HIC"\n$N����˵������СС���磬������λ��$n��ϲ��ʹ˽�������л��ҹ��٣�\n"NOR, ob,me);
   command("gongxi " + me->query("id"));

   me->set_temp("party_finish",1);
   me->delete_temp("party_start_already");
   me->delete_temp("host_of_party");
	message("vision","\nһ�ԵĻ�����Ů��æ�����Ѿ�ϯ�ϵĲи�ʣ����ʰ�ɾ�̧��ȥ��\n",environment(me));
   if(ob1=present("jiuxi", environment(ob)))
      destruct (ob1);
   list = all_inventory(environment(ob));
   i = sizeof(list);
   while (i--)
   {
       usr= list[i];
       ob2=new(__DIR__"obj/xitang");
       ob2->set("name",me->name()+"��"+me->query("couple/couple_name")+"��ϲ��");
       ob2->move(usr);
   }
   tell_room(environment(usr), "\nϲ�ϰ�Ը����µĻ�ư�ϲ��һ�����ط���ÿһ���ˡ�\n");
   remove_call_out("give_money");
   call_out("give_money",1,me,ob);
}

int give_money(object me,object ob)
{
	if( !me || environment(me) != environment(ob) )
   {
   	message_vision("ϲ�ϰ�ͻȻ������һ�������ף���ȥ�����ˣ������յ���𶼲�Ҫ�ˣ���һ��\n"
      "ҡ��ͷһ����������ȥ����ơ�������ŮҲһ���߽�ȥ��ϲ����һ���ӿ������ˡ�\n",ob);
		ob->move("/d/city/empty");//��Ҫֱ��dest���Ա���
	   return  1;
   }
   message_vision("\nϲ�ϰ�Ц�Ǻǵ��ߵ�$N��ǰ��һ���֣��Աߵ�С���������һ��������ϲ�ϰ�˵����\n"
   "������С�ɴ���λ���µĿ������ϵ����һ����"+MONEY_D->price_str((int)ob->query("money"))+"\n"
   "���ڽ��������ɵ��պã���˵�꣬��Ǯ��������$N��Ȼ��һ���߽����ò����ˡ�\n",me);
	MONEY_D->pay_player(me,(int)ob->query("money"));
  	ob->move("/d/city/empty");//��Ҫֱ��dest���Ա���
	return 1;
}

int do_kill(string arg)
{
   object me = this_player();
   object ob = this_object();

   if(!arg || present(arg,environment(ob))!=ob) return 0;

   message_vision("$N��ɫ����ԣ�������ɱ����\n$n��$Nֱҡͷ�����ϲ�����Ӷ��ָ�ʲô����\n", me,ob);
   return 1;
}

int do_exert(string arg)
{
   object me = this_player();
   object ob = this_object();
   message_vision("$N��������һ������\n$n��$N����һ�ۣ�˵���ճԹ�������Ҫ�����ڹ���\n", me,ob);
   return 1;
}

int do_steal(string arg)
{
   object me = this_player();
   object ob = this_object();
   message_vision("$N����֣���Ҫ͵��ʲô��\n$n��$N��������������컯��ʩ�����ԣ�\n",me,ob);
     return 1;
}
