#include <ansi.h>
inherit NPC;
void random_chat();
int ask_go();
int ask_kiss();
int ask_home();
int ask_sm();
int ask_eat();

void create()
{
        set_name(HIW"С��Ů"NOR, ({ "long er", "long","longer"}));
	set("nickname", HIG "�綯�滨" NOR);
	set("long", HIC "\n�����ü�������������˫�۾����崿����һ̶��ˮ��\n"+
	"����ɫ��Ө����ӳ���ں�����֮�£��������ɷ��\n"+
	"������ȻһЦ�����������·����۲���ת֮�䣬\n"+
	"���������飬�������м����ľ��硣\n" NOR);
        set("marry","hxsd");
        set("gender", "Ů��");
 	set("age", 18);
        set("str", 50);
        set("cor", 50);
        set("baohu","hxsd");
        set("couple/couple_name","С����");
        set("cps", 50);
        set("int", 50);
        set("dex", 800);
        set("per", 100);
        set("agi",55);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.dugulianjian" :),
                (: perform_action, "sword.yiji" :),
                (: perform_action, "sword.san" :),
        }) );

        set("combat_exp", 800000+random(8000000));
        set("score", 9000);
        set("shen", 9000);

        set("max_qi",800+random(11900));
        set("max_jing",800+random(11900));
        set("max_sen",800+random(11900));
        set("max_neili",8000+random(11900));
        set("neili",8000+random(11900));
        set("max_mana",800+random(11900));
        set_skill("yangyanshu", 350);
        set_skill("yunv-xinfa", 350);    //��Ů�ķ�
        set_skill("sword", 350);
        set_skill("yunv-jian", 250);     //��Ů��
        set_skill("quanzhen-jian",280);  //ȫ�潣
        set_skill("dodge", 260);
        set_skill("yunv-shenfa", 500);   //��Ů��
        set_skill("parry", 250);
        set_skill("hubo", 220);          //˫�ֻ���
        set_skill("unarmed",250);
        set_skill("meinv-quan", 260);    //��Ůȭ��
        set_skill("literate",250);
        set_skill("qufeng",250);         //����֮��
        set_skill("wuzhan-mei",250);
        set_skill("dodge",500);
        set_skill("spells",300);
        set_skill("magic-old",300);
        map_skill("force", "yunv-xinfa");
        map_skill("spells", "magic-old");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "yunv-jian");
        map_skill("unarmed", "meinv-quan");
        set("chat_chance", 10);
        set("chat_msg", ({
"С��Ůգ��գ�۵������ǲ�����·�˰ɣ�����\n",
"С��Ů��ͷһ�ӣ���ͷ�ڷ����Ʈ��������Ů�·�һ�㡣\n",
		(: command, "blink" :),
		(: command, "blush" :),
		(: command, "flook" :),
		(: command, "lovelook" :),
		(: command, "sleep hxsd" :),
                (: command, "kiss hxsd" :),
                (:random_chat:),
        }) );
	set("chat_chance_combat", 90);  
        set("chat_msg_combat", ({
                (: perform_action, "spells.magic1" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),
        }));
        set("force",18888);
        set("max_force",18888);
        set("force_factor",30);
	set_temp("apply/attack", 200);
	set_temp("apply/damage", 500);
        set_temp("apply/armor", 800);
       set("inquiry", ([
            "��" : (: ask_go :),
            "����" :  (: ask_kiss :),
            "�ؼ�" :  (: ask_home :),
            "�ͷ�" :  (: ask_sm :),
            "����" :  (: ask_eat :),
	]));
	setup();
        carry_object(__DIR__"baiyi");
        carry_object(__DIR__"snj")->wield();
        carry_object(__DIR__"cloth")->wear();
        carry_object(__DIR__"jindai")->wear();
        add_money("gold", 50);

}

int init()
{
 object ob;
ob = this_player();
::init();
if (userp(ob))
       add_action("do_quit","kill");
       add_action("do_att","att");
       add_action("do_ting","ting");
       add_action("do_send","sendto");
       add_action("do_sha","sha");
       add_action("do_sex","sex");
remove_call_out("greeting");
call_out("greeting", 1, ob);
}
void random_chat()
{
  string *e,str="";
   int i;
   object npc,*inv;
   
   inv=all_inventory(environment(this_object()));
	if(!sizeof(inv))	return;
 
   e = sort_array(EMOTE_D->query_all_emote(), 1);
   str=e[random(sizeof(e))];
   command(str+" "+inv[random(sizeof(inv))]->query("id"));
   set("answer",str);  
   return;
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
if(ob->query("id")=="hxsd")
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
        if (this_player()->query("id")=="hxsd")
	   {
           write( HIY "С��Ů��:���˴��Ҷ�����ɽ,���˶��Ҽ����д����\n" NOR);
           write( HIY "Ҫ�ҷ�������,��һ�����ġ�\n" NOR);
	   command("nod");
           command("guard "+ me->query("id") );
           set_leader(me);
           new_name = me->query("name")+"��Ѿ��"+HIW"С��Ů"NOR;
           new_id=me->query("id")+"'s long er";
           set("name",new_name);
           set("id",new_id);
	   write( "����ָ��:\aatt sb ����ĳ��.\nsha sb ɱ��ĳ��.\nting ֹͣս��.\nsendto sb.--��С��Ů�͸�sb.\n");
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
kill_ob(me);
me->fight(this_object());
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
command("halt");
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

void kill_ob(object ob)
{
if (ob->query("id")=="hxsd")
{
command("say �Ҷ����˾��ľ���,��������ΪʲôҪɱ�Ұ�");	
command("die");
call_out("destroying", 5,ob);   
   return;      
}
}

int do_quit(string arg)
{
        object ob= this_object();
	object me= this_player();
	if(arg=="hxsd") {
        write(this_player()->query("name")+"��������ʲô��\n");
        command("kill " + me->query("id"));
        return 1;
	}
}
void destroying(object ob)
{   
object me=this_player();
command("say �ҵ�����ࡣ����\n");
command("say "+me->query("name")+"�����Ժ��Ҳ��ܼ����ٷ������ˡ�����\n");
command("say ������ء�����\n");
command("say ���ء�����\n");
message_vision("$N˵�գ��������ض������������ĵ��ڵ��ϡ�����\n",this_object());
this_object()->die();
   return;      
}