#include <ansi.h>
inherit NPC;
//inherit F_UNIQUE;
int ask_go();
int ask_kiss();
int ask_home();
int ask_sm();
int ask_eat();

void create()
{
        set_name("С��Ů", ({ "long er", "long","longer"}));
	set("nickname", HIM "�綯�滨" NOR);
	set("long", HIC "\n�����ü�������������˫�۾����崿����һ̶��ˮ��\n"+
	"����ɫ��Ө����ӳ���ں�����֮�£��������ɷ��\n"+
	"������ȻһЦ�����������·����۲���ת֮�䣬\n"+
	"���������飬�������м����ľ��硣\n" NOR);
        set("marry","caobin");
        set("gender", "Ů��");
 	set("age", 18);
        set("str", 50);
        set("cor", 50);
        set("baohu","caobin");
        set("cps", 50);
        set("int", 50);
        set("per", 100);
        set("agi",55);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.dugulianjian" :),
                (: perform_action, "sword.yiji" :),
//   	  (: command, "full" :),
        }) );

        set("combat_exp", 50000+random(800000));
        set("score", 9000);
        set("shen", 9000);

        set("max_qi",500+random(1190));
        set("max_jing",500+random(1190));
        set("max_sen",500+random(1190));
        set("max_neili",500+random(1190));
        set("neili",500+random(1190));
        set("max_mana",500+random(1190));
        set_skill("dodge",900);
        set_skill("parry", 100);
        set_skill("dodge", 900);
        set_skill("force", 88);
        set_skill("literate", 88);
	set_skill("sword", 100);
        set_skill("unarmed",88);
        set_skill("xianglong-zhang",88);
        set_skill("dugu-steps",105);
        set_skill("dugu-jian",100);
        set_skill("dugu-steps",100);
        map_skill("dodge", "dugu-steps");
	map_skill("sword", "dugu-jian");
	map_skill("force", "dugu-force");
	map_skill("parry", "dugu-jian");
	map_skill("unarmed", "xianglong-zhang");
        set("chat_chance", 1);
        set("chat_msg", ({
//		(: command, "caobin caobin" :),
"С��Ůգ��գ�۶���������Ц��Ц�������ǲ�����·�˰ɣ�����\n",
"С��Ů��ͷһ�ӣ���ͷ�ڷ����Ʈ��������Ů�·�һ�㡣\n",
		(: command, "blink" :),
		(: command, "blush" :),
		(: command, "flook" :),
		(: command, "lovelook" :),
		(: command, "sleep caobin" :),
        }) );
        set("force",18888);
        set("max_force",18888);
        set("force_factor",30);
	set_temp("apply/attack", 15);
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 15);
       set("inquiry", ([
            "��Ը��Ը�������" : (: ask_go :),
            "����" :  (: ask_kiss :),
            "�ؼ�" :  (: ask_home :),
            "�ͷ�" :  (: ask_sm :),
            "�Է�" :  (: ask_eat :),
	]));
	setup();
        carry_object("/cao/long/baiyi");
        carry_object("/cao/obj/roommaker");
        carry_object("/cao/long/sword")->wield();
        carry_object("/cao/long/cloth")->wear();
        carry_object("/cao/long/jindai")->wear();
        add_money("gold", 50);

}

int init()
{
 object ob;
ob = this_player();
::init();
if (userp(ob))
if(random(10)>5)
      add_action("do_att","att");
       add_action("do_ting","ting");
       add_action("do_send","sendto");
       add_action("do_sha","sha");
       add_action("do_sex","sex");
remove_call_out("greeting");
call_out("greeting", 1, ob);
}

void smiling (object who)
{
  if (random(2))
    command("smile");
  else
    command("smile "+who->query("id"));
}

void greeting(object ob)
{
if( !ob || environment(ob) != environment() ) return;
if(!userp(ob)) return;
message_vision(	"$N��$n��ȻһЦ.\n\n",this_object(),ob );
if(ob->query("id")=="caobin")
{
	  command("say�ޣ�"+ob->query("name")+"���˻����ˡ�");
}
else
{
command("say ��λ" + RANK_D->query_respect(ob)
+ "�����Ǵ�������?�����\n");
if (ob->query("gender") == "����"||ob->query("gender") == "����")
{
       message_vision(
	HIM "$Nһ����С��Ů�����ɵ��������һ�����ؿ����类һ��\n"+
	"���ε��������ػ���һ�£����Ǽ䴽�����Ŀ�ɿڴ���\n"+
	"�ĵ��������ˣ������ˣ�����������������Ů?\n"+
	"�������ٶ���ЦһЦ���Ҿ�������Ҳ�ĸʰ�!...\n" NOR,ob,this_object());
 	command("xixi");
}
else
{
       message_vision(
	HIM "$Nһ��С��Ů�����ɵ��������һ�����ؿ����类һ��\n"+
	"���ε��������ػ���һ�£����Ǽ䴽�����Ŀ�ɿڴ���\n"+
	"�ĵ��������ˣ������ˣ�����������������Ů?\n"+
	"������Ҳ�����ӣ���Ҫ��Ϊ��ȥ������Ҳ������һ��ü...\n" NOR,ob,this_object());
	command("say �������������������ң��������ȴ����һλ" + RANK_D->query_respect(ob)+"\n");
}
}
}

int ask_kiss()
{
  object me;
  string new_name,new_id,host_id;
  me=this_player();
  if(query("id")!="long er")
        {
	 sscanf(query("id"),"%s's long er",host_id);
	 if(me->query("id")==host_id)
           {
	   if(random(10)>1)	          
           {
	   say(query("name")+"�����ߵ�ͨ��,����ͷ��,�����ĵ��˵�ͷ.\n");
           command("lovelook "+ me->query("id") );
           command("cat "+ me->query("id") );
           command("kiss "+ me->query("id") );
           write(CYN"���С��Ů΢΢һЦ����¶�����޵�ϲ��֮�顣\n"NOR);
           write(CYN"С��Ů������ȻһЦ�����������·�������ɫ��Ө����\n"NOR);
           me->add("force",10000);
           me->add("qi",10000);
           me->add("jing",10000);
           me->add("sen",10000);
           me->add("combat_exp",2000);
           }		
           else 
	   say(query("name")+"����һ��,һ����������ȥ,˵:����,��Ҫ.\n");
	   return 1;
           }
	}
say(query("name")+"˵��:��,�Ҳ���.");
return 1;
}

int ask_go()
{
  object me;
  string new_name,new_id,host_id;
   me=this_player();
	   if(query("id")!="long er")
        {
		 sscanf(query("id"),"%s's long er",host_id);
		 if(query("id")==host_id)
           {say(query("name")+"�����۾����˿�"+
				me->query("name")+"��˵:��ȻԸ����,�Ҷ�����ġ�\n");
            return 1;
           }
	 if(me->query("id")!=host_id)
           {say(query("name")+"�����۾����˿�"+
				me->query("name")+"��˵:���е�,�ҵ��������˵ġ�\n");
			return 1;
           }
	 }
      	if((int) me->query_skill("dugu-jian",1) > 300)
      //  if ((int)this_player()->query_skill("dugu-jian")>300)
	   {
           write( HIY "С��Ů��:���˴��Ҷ�����ɽ,���˶��Ҽ����д����\n" NOR);
           write( HIY "Ҫ�ҷ�������,��һ�����ġ�\n" NOR);
	   command("nod");
           set_leader(me);
       new_name = me->query("name")+"��Ѿ��С��Ů";
       new_id=me->query("id")+"'s long er";
       set("name",new_name);
       set("id",new_id);
	   write( "����ָ��:\nattack sb ����ĳ��.\nsha sb ɱ��ĳ��.\nstop ֹͣս��.\nsendto sb.--��С��Ů�͸�sb.\n");
                  set("long","����"+new_name+"��\n"
       "�����ü�������������˫�۾����崿����һ̶��ˮ��\n"
	"����ɫ��Ө����ӳ���ں�����֮�£��������ɷ��\n"
	"������ȻһЦ�����������·����۲���ת֮�䣬\n"
	"���������飬�������м����ľ��硣\n"
	"С��ŮЦ���绨,��Ц�����ؿ����㡣\n");
       }
	   else say(query("name")+"�����۾�����"+
				me->query("name")+"��˵:���е�,����û��ͬ�⡣\n");
return 1;
}

int ask_home()
{
  object me;
  string new_name,new_id,host_id;
  me=this_player();
  if(query("id")!="long er")
        {
	 sscanf(query("id"),"%s's long er",host_id);
	 if(me->query("id")==host_id)
           {
	   if(random(10)>3)	          
           {
	message("vision",
		 name() + "˵������������Ҫ�ҷ������뷢��Ϊ�����ҵ��㰡��\n\n"
		+ name() + "����������ʧ�����ˡ�\n" , environment(),
		this_object() );
//        if(objectp(owner=this_object()->query("possessed")))
		me->add_temp("max_guard",-1);
	destruct(this_object());
           }		
           else 
	   say(query("name")+"����һ��,����ϸ���˵:����"+me->query("name")+"����,��Ҫ.�Ҳ�Ҫ�ؼ�\n");
	   return 1;
           }
	}
say(query("name")+"˵��:����˭�����ֲ���ʶ�㣬�Ͳ�����ģ�");
return 1;
}
int ask_sm()
{
  object me;
  string new_name,new_id,host_id;
  me=this_player();
  if(query("id")!="long er")
        {
	 sscanf(query("id"),"%s's long er",host_id);
	 if(me->query("id")==host_id)
           {
	   if(random(30)>2)	          
           {
           command("shiver");
           say(query("name")+"����һ��,������˵:������,"+me->query("name")+"��������ң����Ҷ����ԣ�����Ҫ������\n");
 	   return 1;
           }		
           else 
       write( CYN "��а���Ц��Ц��Ȼ��ӻ����ó�һ�����Ӻ�һ��������XX�Ķ���..... \n"NOR);
       command("shiver");
       write( CYN "��ֱ���������С��Ů����ȹ��������������"+"\n" NOR);
       write( CYN "���ó����Ӻ�һ�������Ķ�����Ȼ����С��Ů...XXX��������"+"\n" NOR);       
       write( CYN "............................."+"\n" NOR);
       write( CYN "......................."+"\n" NOR);
       write( CYN "...................."+"\n" NOR);
       write( CYN "................."+"\n" NOR);
       write( CYN ".............."+"\n" NOR);
       write( CYN "............"+"\n" NOR);
       write( CYN ".........."+"\n" NOR);
       write( CYN "........"+"\n" NOR);
       write( CYN "......"+"\n" NOR);
       write( CYN "...."+"\n" NOR);
       write( CYN "..."+"\n" NOR);
       write( CYN ".."+"\n" NOR);
       write( CYN "��һ��������ֻ��С��Ů���۷�����������գ�һ��Ҳ���ӡ�"+"\n" NOR);
     	   if(random(10)>3)	          
           {
command("say �ҵ�����ࡣ����\n");
command("say "+me->query("name")+"�����Ժ��Ҳ��ܼ����ٷ������ˡ�����\n");
command("say ������ء�����\n");
command("say ���ء�����\n");
message_vision("$N˵�գ��������ض������������ĵ��ڵ��ϡ�����\n",this_object());
	set("long", HIC "\n�����ü�������������˫�۾����崿����һ̶��ˮ��\n"+
	"����ɫ��Ө����ӳ���ں�����֮�£��������ɷ��\n"+
	"�������ض���,���������˻�����ô������\n" NOR);
this_object()->die();
           return 1;
           }		
             write( CYN "С��Ů�ܿ�������˵���������㣬�ſ��Ұɡ��� \n"NOR);
        set("name","����������С��Ů");
             return 1;
           }
	}
say(query("name")+"��������:�����ģ����и���̬����");
command("kill "+ me->query("id") );
return 1;
}

int ask_eat() 
{
object me;
object wo;
  string new_name,new_id,host_id;
  me=this_player();
  if(query("id")!="long er")
        {
	 sscanf(query("id"),"%s's long er",host_id);
	 if(me->query("id")==host_id)
           {
me = this_player();
message_vision("$N�ó���һЩ�������ϣ������˻�Ϊ����$n������������\n",this_object(),me);
       write( CYN ".................."+"\n" NOR);
       write( CYN "..............."+"\n" NOR);
       write( CYN "............"+"\n" NOR);
       write( CYN "........."+"\n" NOR);
       write( CYN "......"+"\n" NOR);
       write( CYN "...."+"\n" NOR);
       write( CYN "..."+"\n" NOR);
       write( CYN ".."+"\n" NOR);
       write( CYN "."+"\n" NOR);
       write( CYN "С��Ů������ķ�װ�ڼ��������������"+"\n" NOR);
       write( CYN "С��Ů�ӻ����ó���������ͷ��վ�����Ա߳���������"+"\n" NOR);
            set ("food",170);
            set ("water",170);
            switch( random(22) ) {
		case 0:
	wo = new(__DIR__"obj/s0");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
		case 1:
	wo = new(__DIR__"obj/s1");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
		case 2:
	wo = new(__DIR__"obj/s2");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
		case 3:
	wo = new(__DIR__"obj/s3");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 4:
	wo = new(__DIR__"obj/s4");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
              case 5:
	wo = new(__DIR__"obj/s5");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 6:
	wo = new(__DIR__"obj/s6");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 7:
	wo = new(__DIR__"obj/s7");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
              case 8:
	wo = new(__DIR__"obj/s8");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 9:
	wo = new(__DIR__"obj/s9");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
              case 10:
	wo = new(__DIR__"obj/s10");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 11:
	wo = new(__DIR__"obj/s11");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 12:
	wo = new(__DIR__"obj/s12");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
              case 13:
	wo = new(__DIR__"obj/s13");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 14:
	wo = new(__DIR__"obj/s14");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 15:
	wo = new(__DIR__"obj/s15");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
              case 16:
	wo = new(__DIR__"obj/s16");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 17:
	wo = new(__DIR__"obj/s17");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 18:
	wo = new(__DIR__"obj/s18");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
              case 19:
	wo = new(__DIR__"obj/s19");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 20:
	wo = new(__DIR__"obj/s20");
	wo->move(me);
	wo = new(__DIR__"obj/w2");
	wo->move(me);
              return 1;
              case 21:
	wo = new(__DIR__"obj/s21");
	wo->move(me);
	wo = new(__DIR__"obj/w1");
	wo->move(me);
              return 1;
}
           }
	}
say(query("name")+"���ʲôΪ�����������ֲ��������ˣ���");
command("kick "+ me->query("id") );
return 1;
}

int do_att(string arg)
{
  object ob; 
  string host_id;
  object me=this_player();
  if(query("id")=="long er")
   {say("����Ȩʹ�ô����\n");
    return 0;}
  sscanf(query("id"),"%s's long er",host_id);
  if(me->query("id")!=host_id)
  return notify_fail("С��Ů���������㣡\n");
  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("С��Ůɵɵ�������㣬�����������˼��\n");
  if(!living(ob)) 
	 return notify_fail("С��Ů˵:"
              +ob->query("name")+"�Ѿ��������㻹Ҫ...??!!\n");
  message_vision("С��Ů������$N��ͷ��: ��,�õ�.\n",me);
  fight_ob(ob);
  return 1;
}

int do_ting()
{
   string host_id;
  object me=this_player();
  if(query("id")=="long er")
   return notify_fail("����Ȩʹ�ô����\n");
  sscanf(query("id"),"%s's long er",host_id);
  if(me->query("id")!=host_id)
   return notify_fail("С��Ů���������㣡\n");
 if(!is_fighting())
	 return notify_fail("С��Ů����û���˴�.\n");
 message_vision("С��Ů������$N΢΢һЦ��������սȦ��\n",me);
 command("halong");
 return 1;
}

int do_send(string arg)
{
  object ob; string host_id,new_name,new_id;
  object me=this_player();
  if(query("id")=="long er")
   return notify_fail("����Ȩʹ�ô����\n");
  sscanf(query("id"),"%s's long er",host_id);
  if(me->query("id")!=host_id)
   return notify_fail("С��Ů���������㣡\n");

  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("��Ҫ��С��Ů�͸�˭��\n");
  if(!living(ob)) 
	 return notify_fail("��ֻ�ܰ�С��Ů������!\n");
 message_vision("С��Ů������������������$N��˵:\n���˴��Һ�,��������;���˴��Ҳ���,�����������.\n",me);
 set_leader(ob);
 new_name = ob->query("name")+"��Ѿ��С��Ů";
	   set("long","����"+new_name+"��\n"
		"����һ���崿���׵���Ů,��Լʮ��,�������;\n"
	            "�����ü�������������˫�۾����崿����һ̶��ˮ��\n"+
	            "����ɫ��Ө����ӳ���ں�����֮�£��������ɷ��\n"+
		"һ��ѩ�׵�����,ü����С,ȴ���Ǹ������۸�,���������ؿ����㡣\n");
 new_id=ob->query("id")+"'s long er";
 set("name",new_name);
 set("id",new_id);
 write( HIY "С��Ů��������"+ob->query("name")+"����������ӯӯһ�ݡ�\n" NOR);
 message_vision("����ָ��:\att sb ����ĳ��.\nsha sb ɱ��ĳ��.\nting ֹͣս��.\nsendto sb.--��С��Ů�͸�sb.\n",me);
 return 1;
}

int do_sha(string arg)
{
        int i ;
	object me,ob;
	object* obj;
	me = this_object();
        if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("��ҪС��Ůɱ˭��\n");
	if(!environment(ob)->query("no_fight"))
	{
        message_vision("С��Ů��$N��ͷ˵��: ��,�õ�.\n",me);
	command("say ��,����Ҫ��ɱ����!");
	remove_call_out("kill_ob");
  	call_out("kill_ob", 1, ob); 
	}
	return 1;
}       

int do_sex(string arg)
{
       string host_id;
       object me=this_player();
       if(query("id")=="long er")
       return notify_fail("����Ȩʹ�ô����\n");
       sscanf(query("id"),"%s's long er",host_id);
           if(me->query("id")!=host_id)
          return notify_fail("С��Ů��Ҫɱ���������å��\n");
       command("shiver");
       command("say �Ѿ�������"+me->query("name")+"�����㻹Ҫ...??!!");
       command("remove cloth");
       write( CYN "С��Ů������һ�������������·�..... \n"NOR);
       write( CYN "С��Ů����¶����������ɫ��"+"\n" NOR);
       write( CYN "С��Ů�����ı�ס���㡣Ȼ������...XXX��������"+"\n" NOR);       
       write( CYN "......................."+"\n" NOR);
       write( CYN "...................."+"\n" NOR);
       write( CYN "................."+"\n" NOR);
       write( CYN ".............."+"\n" NOR);
       write( CYN "............"+"\n" NOR);
       write( CYN ".........."+"\n" NOR);
       write( CYN "........"+"\n" NOR);
       write( CYN "......"+"\n" NOR);
       write( CYN "...."+"\n" NOR);
       write( CYN "..."+"\n" NOR);
       write( CYN ".."+"\n" NOR);
       write( CYN "��һ��������ֻ��С��Ů���������������㡣һ��Ҳ���ӡ�"+"\n" NOR);
       write( CYN "С��Ů�����ش������·�������������������ɡ� \n"NOR);
       command("wake");
       command("wear cloth");
       me->add("force",10000);
       me->add("qi",10000);
       me->add("jing",10000);
       me->add("sen",10000);
       return 1;
}
