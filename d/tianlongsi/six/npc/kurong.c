// kurong.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
string ask_liumai1();
string ask_liumai2();
int ask_dudan(object who);
void create()
{
	set_name("�����ʦ", ({ "ku zhu","ku"}) );
	set("gender", "����" );
	set("title", "�����µ�ʮ����ɮ��");
	set("class", "bonze");
	set("long", 
"������������֮������ߵ�һ����ɫ����Ƥ���⻬������Ӥ����
�ұߵ�һ��ȴ��ݹǣ�����һ�Ž��Ƶ���Ƥ֮��ȫ�޼��⣬��ͷͻ
�˳�������Ȼ���ǰ�����ù�ͷ����������ϰ�����������¡�\n");
	set("age", 100);
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 50);
	set("combat_exp", 2500000);
	set("score", 1000000);
	set("book_count", 1);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("finger", 250);
	set_skill("sword", 200);
	set_skill("tiannan-step", 250);
	set_skill("kurong-changong", 300);
	set_skill("duanjia-sword", 250);
	set_skill("six-finger", 300);
	set_skill("sun-finger", 300);
	set_skill("buddhism", 300);
	set_skill("literate", 100);
	set("book_give", 1);
	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("parry", "six-finger");
	map_skill("finger", "six-finger");
	map_skill("sword", "duanjia-sword");
	prepare_skill("finger","six-finger");

        set("inquiry", ([
	"���ƶ�" : (: ask_liumai2 :),
	"����" : (: ask_liumai1 :),
        ]) );

	create_family("����μ�",16,"��ɮ");

	setup();
	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


string ask_liumai1()
{
        object ob;
        ob=this_player();
       
		if( ob->query("dali/meet_dy1")||ob->query("liumai_update"))
		   {
		    ob->set_temp("liumai/find1",1);   
           return "��������汣��,����ǰ�ձ���ѩɽ���������Ħ�Ǹ�ץ���ˣ�
		   �������Դ��񣬶��ܷ��׻����������ӷ�! \n";
		      } else
		if( ob->query("dali/meet_dy2"))
		   {  
		   return "��˵�����Ѿ����˴�Ȼ����ˣ��������Ұ��������ӷ� \n";
            } else {
		   return "���������������������������Ĺ��ӣ���˵���ʴ��������Դ��� \n";
           		   }
}

string ask_liumai2()  
{
        object me,ob,*thing;
	mapping myfam;
	int i;
	ob=this_player();
	me=this_object();
      
      
        myfam = (mapping)ob->query("family");
 
      if (myfam["family_name"] != "����μ�"||ob->query("class") != "bonze") 
         {
	 return "�Բ����Ҳ�֪����\n";
        
	}
      if (ob->query("liumai_pass") && (ob->query_skill("six-finger",1)<200))
         {
         
          command ("nod" + ob->query("id"));
          message_vision("������һ�������ȥ������Ȼ�ƿ�һ��ʯ�ţ�"+ob->query("name")+"��Ҳ���������˹�ȥ��\n",ob);
          thing = deep_inventory(ob);
	  i = sizeof(thing);
	    while (i--)
	       if (thing[i]->is_character()) {
		   message_vision("������ͻȻ����һ������������ô�����˽�������\n", ob);
		   me->set_leader(ob);
                   remove_call_out("kill_ob");
                   call_out("kill_ob", 0, me); 
	           return " ";
		} 
	
	ob->move("/d/tianlongsi/six/pyd");
	return "";
	  }   	
      if( ob->query_skill("yiyang-zhi",1)<160 )
	 {
	 return "���һ��ָ��������ô�������ȥ�ú�����!!\n";
		}
      if (ob->query("max_neili")<2000)
      {
	 return "���������������ô�������ȥ�ú�����!!\n";
	
       }
       if (ob->query_temp("try_fight"))
           return "�㲻�����ڽ��ҵ�����!\n";
       
       if (ob->query_temp("try"))
           return "�����׼�����ˣ���ȷ��(try). \n";
           
       if (me->query_temp("try"))
           return "�Բ���������������׼������. \n";    
       
       if (me->query_temp("try_fight"))
           return "�Բ�����������æ�ţ�����ʲôҪ��һ�����˵. \n";  
      	 
      if( ob->query_skill("six-finger",1)>200)
         {  
	 ob->set("liumai_update",1);
        
	 return "�����������Ϊ�Ѿ��Ƿ��켶����������Ҳ���ܸ���ʲô������.
	               ��ȥ�����������Ӷ����ɣ�Ҳ�����ܸ���Щ������  \n";
	 
	   } else 
	   {
          command("say �������������ϴ��¹�أ�" + RANK_D->query_respect(ob) + "����������ʮ�в������裬�Ź��ʸ�����ƶ���ϰ�����񽣡�");
          ob->set_temp("try",1);
          me->set_temp("try",1);
          call_out("wait", 1, me, 0);
          return "�����׼�����˽��У���ȷ����try)��\n";
		   }
}
void init()
{
	add_action("do_yes", "try");
}

  int do_yes()
{
        object me,ob,room;
        ob = this_player();
        me = this_object();

	if( !ob->query_temp("try") )
		return 0;
	message_vision("$N����һ��������˵�������롱��\n",ob );
        set("max_jing",8000);
        set("jing",8000);
        set("eff_jing",8000);
        set("eff_jingli",8000);
        set("max_qi",8000);
        set("qi",8000);
        set("eff_qi",8000);
        set("jiali",100);
        set("neili",16000);
        set("max_neili",16000); 
        command("yun rong");
        if(!( room = find_object("/d/tianlongsi/six/lsy" )) )
                room = load_object("/d/tianlongsi/six/lsy");
        room->delete("exits");
        ob->delete_temp("try");
        me->delete_temp("try");
        me->set_temp("try_fight",1);
        ob->set_temp("try_fight",1);        
        call_out("fighting",  3, me, ob, 0);
        message_vision("�����ʦ˫�ƺ�ʲ������һҾ�����������ĵ�������ָ�̡���\n",ob);
        return 1;
        
        
}

void waiting(object me, int wait_time)
{
	object fighter;

        if( wait_time >= 150 )
	{
		say( "�����ʦ˵���������㲻�������ʮ���ˣ�\n\n");
		call_out("do_recover", 0, me);		
		return;
	}
	if( !objectp( fighter = present( me->query_temp("fight"), environment(me) ) ) )
	{
                call_out("waiting", 1, me, wait_time + 1);
		return;
	}
	
}
void fighting(object me, object fighter, int count)
{
	object room;	
	 
	if (!fighter || !living(fighter) || environment(fighter)!=environment(me)
	|| fighter->query("qi") < 1)
	{
		if(!( room = find_object("/d/tianlongsi/six/lsy" )) )
                room = load_object("/d/tianlongsi/six/lsy");
		if( objectp(fighter)) {
			fighter->delete_temp("try_fight");
			fighter->delete_temp("beat_count");
		}
		me->delete_temp("try_fight");
		room->set("exits/out","/d/tianlongsi/six/songlin-1");
                command("chat* ҡ��ҡͷ��˵�����벻��... ����");
		command("sigh");
		return;
		
	} else if (count <10) {
	if (interactive(fighter) && fighter->query_temp("try_fight") && living(fighter))
	 COMBAT_D->do_attack(this_object(), fighter, query_temp("weapon"), 2);
	 count++;
	  call_out("fighting", 2, me, fighter, count);
	} else call_out("do_congra", 3, me, fighter);
	
}
void do_congra(object me, object fighter)
{
	int i;
	object room,*thing;
	 if(!( room = find_object("/d/tianlongsi/six/lsy" )) )
                room = load_object("/d/tianlongsi/six/lsy");
	fighter->delete_temp("try_fight");
	fighter->set("liumai_pass",1);
	me->delete_temp("try_fight");
	command("smile");
        command("say ��ϲ����ϲ���㼼���������ʤ������������ϰ������������,��ȥ�ɡ�\n");
	room->set("exits/out","/d/tianlongsi/six/songlin-1");
	message_vision("������һ�������ȥ������Ȼ�ƿ�һ��ʯ�ţ�"+fighter->query("name")+"��Ҳ���������˹�ȥ��\n",fighter);
        thing = deep_inventory(fighter);
	  i = sizeof(thing);
	    while (i--)
	       if (thing[i]->is_character()) {
		   message_vision("������ͻȻ����һ������������ô�����˽�������\n", fighter);
		   me->set_leader(fighter);
                   remove_call_out("kill_ob");
                   call_out("kill_ob", 0, me); 
	           return;
		} 
	 fighter->move("/d/tianlongsi/six/pyd");
         return;
	
}
