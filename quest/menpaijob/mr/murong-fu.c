 // /u/beyond/mr/npc/murong-fu.c  Ľ�ݸ�
// this is made by beyond
// update 1997.6.23
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_fail();
string ask_bo();
string ask_skill();
string ask_wang();
string ask_dan();
string ask_dan1();
string ask_ge();
string ask_sword(); 
string ask_book();
string ask_book2();
object ob = this_object();

void create()
{
	set_name("Ľ�ݸ�",({"murong fu","murong","fu"}));
        set("title","����Ľ�ݹ���");
        set("nick","�Ա�֮�� ��ʩ����");
	set("long", 
              "���������ºų��Ա�֮��������֮��Ĺ���Ľ�ݸ���\n"
              "�����ϴ��Ų���һ����Ц�ݡ�\n");
        set("age", 27);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
       set("per", 30);
	
	set("max_qi", 13500);
	set("max_jing", 13000);
	set("neili", 33500);
	set("max_neili", 33500);
	set("jiali", 50);
	set("combat_exp", 8000000);
        set_skill("strike",270);
        set_skill("finger",270);
        set_skill("dodge",280);
        set_skill("force", 170);
	set_skill("canhe-zhi", 380);
	set_skill("murong-jianfa",260);       
        set_skill("shenyuan-gong", 280);
	set_skill("yanling-shenfa", 320);   
	set_skill("xingyi-zhang",280);
        set_skill("douzhuan-xingyi", 280);
	set_skill("parry", 280);
	set_skill("sword", 260);
	set_skill("literate", 250);
        set_skill("murong-daofa", 280);
        set_skill("blade",260);
        
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("strike", "xingyi-zhang");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");

	prepare_skill("finger","canhe-zhi");
	prepare_skill("strike","xingyi-zhang");
        
        create_family("����Ľ��",2,"����");

       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "parry.xingyi" :),
                (: perform_action, "parry.xingyi" :),
                (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.qixing" :),
                (: perform_action, "dodge.yanling" :),                
                (: perform_action, "dodge.yanling" :),                
        }));
               	set("inquiry", 
                ([
                        "name" : "�Ҿ����Ա�֮������ʩ����Ĺ���Ľ�ݸ���\n",
                        "here" : "�����Ǵ��������������룬�ѵ���û����˵����\n",
                        "rumors" : "�Ҹ�ͻȾ�񼲣����������˼����һ�涼û���������¶������Σ�\n",
                        "����" : "�ҵĹ���ס����٢��ɽׯ���������������µ������񶴡�\n",
                        "��ʩˮ��" : (: ask_ge :),
                        "Ľ�ݲ�" : (: ask_bo :),
                        "����" : (: ask_book :),
                        "������" : (: ask_wang :),
                        "����" : (: ask_sword :),
                       	"��ת����"  : (: ask_skill :),
                        "��Ԫ��" : (: ask_dan :),
                        "ͼ��" : (: ask_book2 :),
                "����" : (: ask_job() :),
                "job" : (: ask_job() :),
                "ʧ��" : (: ask_fail() :),
                ]));
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        set("dan_count", 6);
       	set("book_count",1);
        set("book2_count" ,1);
        set("dan1_count", 10);
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
    carry_object("/clone/misc/cloth")->wear();
}
int count = 0;
void reset()
{
    count = 1 - count;
    if (count) return;
        set("dan_count", 6);
        set("book_count",1);
        set("book2_count" ,1);
        set("dan1_count", 10);
}
void init()
{
        ::init();
        add_action("do_jiaoliang", "jiaoliang");
}
void attempt_apprentice(object ob)
{
if (ob->query_skill("parry", 1) < 100) {
		command("say �ҹ���Ľ���Ա�֮������ʩ������м�Ҫ�����ߣ�С�ֵ��ƺ�����ѧϰ��");
    command("say " + RANK_D->query_respect(ob) + "�Ĺ���������������ذɡ�");
		return;
	}

        if (ob->query_skill("shenyuan-gong", 1) < 100) {
		command("say �ҹ���Ľ���Ա�֮������ʩ������ڹ��ķ�Ҫ�����ߣ�С�ֵ��ƺ�����ѧϰ��");
    command("say " + RANK_D->query_respect(ob) + "�Ĺ���������������ذɡ�");
		return;
	}

            command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say �������ϣ����ҹ���Ľ���ֵ�һ���ģ�Ϊ�����Ҵ������һ��������");
        command("chat ����˵��������������һ���ģ������˸�ָ�տɴ�����");
        command("chat* haha"); 
	command("recruit " + ob->query("id"));
	ob->set("title","����Ľ�ݵ���������");
}

 

string ask_wang()
{
mapping fam;
// obiect ob;
        if (!fam = this_player()->query("family") || fam["family_name"] !="����Ľ��")
        return RANK_D->query_respect(this_player()) +
        "�뱾��������������֪�˻��Ӻ�̸��";
        return "�������ұ��ã�һֱ������ܵĺ��ϣ����Ҷ��ܳ�ʱ��û�м������ˡ�\n";
}

string ask_skill()
{
mapping fam; 
// object ob;
	if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
		return "��ת��������Ľ�ݼҵľ�ѧ������ע���мܺ�����\n";

}

string ask_ge()
{
mapping fam; 
// object ob
	if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
		return "��ʩˮ������Ľ���ղ������ؼ�֮���ڣ����ҵ���.....\n";
}

string ask_sword()
{
mapping fam; 
// object ob;
	if (!(fam = this_player()->query("family"))
           || fam["family_name"] != "����Ľ��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
		return "��������ү�����ź��������ð�������������úñ��ܣ�\n";
}

string ask_book()
{
	object ob;
	mapping fam; 
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
   if ( fam["master_name"] != "Ľ�ݲ�" && fam["master_name"] != "Ľ�ݸ�")
      	return RANK_D->query_respect(this_player()) + 
		"��������������̸������";

	if (  present("douzhuan xingyi", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����ж�ת���Ƶ��伮�����ô����Ҫ�ˣ� ����̰�����У�";

	if (query("book_count") < 1) return "�Բ��𣬶�ת���Ƶ��伮�Ѿ�������Ҫ���ˡ�";

	ob = new("d/mr/npc/obj/shu1");
	ob->move(this_player());

	add("book_count", -1);

	message_vision("$N�õ�һ����ת���Ƶ��书�ؼ���\n",this_player());
	return "�ðɣ�����ΪĽ�ݼ����Ĺ������Ȿ��ʹ�����ɡ�";

}

string ask_book2()
{
	object ob;
	mapping fam; 
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
         if ( fam["master_name"] != "Ľ�ݲ�" && fam["master_name"] != "Ľ�ݸ�")
      	return RANK_D->query_respect(this_player()) + 
		"��������������̸������";
        if ( (int)this_player()->query_skill("douzhuan-xingyi",1)<50)
             return RANK_D->query_respect(this_player()) + 
		"��������������̸����ȡͼ�⣿";
	if (  present("douzhuan xingyi", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����ж�ת���Ƶ��伮�����ô����Ҫ�ˣ� ����̰�����У�";

	if (query("book2_count") < 1) return "�Բ��𣬶�ת���Ƶ��伮�Ѿ�������Ҫ���ˡ�";

	ob = new("d/mr/npc/obj/shu2");
	ob->move(this_player());

	add("book2_count", -1);

	message_vision("$N�õ�һ����ת���Ƶ��书�ؼ���\n",this_player());
	return "�ðɣ�����ΪĽ�ݼ����Ĺ������Ȿ��ʹ�����ɡ�";

}
 
string ask_dan()
{
	mapping fam; 
      object ob,me; 
               me = this_player();
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

      if ( (int)this_player()->query_condition("medicine" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"���ǲ��ǸճԹ�ҩ����ô����Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

      if ( (int)this_player()->query("max_neili" ) < 400)
		return RANK_D->query_respect(this_player()) + 
		"������������ҩ����к����ˣ�����ʱ�������ɡ�";
           if ((int)me->query("max_neili") >= (int)me->query_skill("force")*10)
  return RANK_D->query_respect(this_player()) + "���������Ҫ��,���书�Ѿ�����,ȥ���������Ϊ��.";
	if (  present("guiyuan dan", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����п�ҩ������ô����Ҫ�ˣ� ����̰�����У�";

	if (query("dan_count") < 1) return "�Բ��𣬹�Ԫ���Ѿ�������Ҫ���ˡ�";

             ob = new("/d/mr/obj/guiyuan-dan");
	ob->move(this_player());

	add("dan_count", -1);

	message_vision("$N���һ�Ź�Ԫ����\n",this_player());
	return "�ðɣ��˵�������������һ�������Ṧ���������Ҿʹ�����ɡ�";

}

string ask_dan1()
{
	mapping fam; 
        object ob,me;
me = this_player();
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

      if ( (int)this_player()->query_condition("bonze_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + 
		"���ǲ��ǸճԹ�ҩ����ô����Ҫ�ˣ� ��ҩ����к����ˣ�����ʱ�������ɡ�";

        if ( (int)this_player()->query("max_neili" ) < 100)
		return RANK_D->query_respect(this_player()) + 
		"������������ҩ����к����ˣ�����ʱ�������ɡ�";

	if (  present("qingxin san", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ����п�ҩ������ô����Ҫ�ˣ� ����̰�����У�";
	if (query("dan1_count") < 1) return "�Բ�����¶����ɢ�Ѿ�������";

	ob = new("d/mr/npc/obj/qingxin-san");
	ob->move(this_player());

	add("dan1_count", -1);

	message_vision("$N���һ����¶����ɢ��\n",this_player());
	return "�ðɣ���ҩ������������һ�������Ṧ���������Ҿʹ�����ɡ�";

}

string ask_bo()
{
        mapping fam; 
//        object ob;
	if ((int)this_player()->query_temp("marks/ʧ��")) 
 return" Ľ�ݸ����з����������⣬ֱ��" + this_player()->name() + "һ��һ��˵�����Ѿ��������ˣ������ỹ
����ȥ����������!";
		 
	 
         if (!(fam =this_player()->query("family")) || fam["family_name"] != "����Ľ��")
		return "���뱾��������������֪�˻��Ӻ�̸��";
  
       if ((int)this_player()->query_temp("marks/bai_bo") && fam["master_name"] == "Ľ�ݲ�") 
         return "���Ѿ��ǼҸ��ĵ����ˣ�����������ѧ��!";

           this_player()->set_temp("marks/jiao", 1);
 return "Ľ�ݸ����з����������⣬ֱ��" + this_player()->name() + "һ��һ��˵�����Ҹ����������֣�����
�����Ի������书δ�ɣ���ò�Ҫȥ��ȥ���裬������������ܽ�����ʮ�У��ͺ��ҽ���һ�¡�(jiaoliang) ";
                
	 
}

int do_jiaoliang()
{
	object me, obj, jiaxin;
	int current_qi, count;

	me = this_object();
	obj = this_player();
        jiaxin = new("d/mr/obj/jiaxin");
	current_qi = (int)me->query("qi");

	say(obj->name() + "��Ľ�ݸ�˵���ðɣ��Ǿ���ʦ��ָ�㼸�� ��\n");
             set("max_qi", 3500);
            set("jiali", 100);
             set("neili", 3500);
             set("max_neili", 3500);
             set("max_jing", 2000);
        if( obj->query_temp("marks/jiao") ) {
                obj->set_temp("marks/jiao", 0);
		count = 0;
		while ( ((int)obj->query("qi")*100 / (int)obj->query("max_qi")) > 30) { 
			if ( !present(obj, environment()) )
				return 1;
                        COMBAT_D->do_attack(obj, me, obj->query_temp("weapon"));
			if (((int)me->query("qi")*100/current_qi)< 30 || ++count > 10) {
				say(
"Ľ�ݸ���" + obj->name() + "˵���� ������Ľ�������ֳ����ģ������д����ţ� �����϶���ǰȥ���֣�\n"
"�������������˼ҡ�ϣ�����ܲ�������������Ľ�����ң��⸴�������\n"
				);
      				jiaxin->move(obj);
				obj->set_temp("marks/bai_bo", 1);
			        message_vision("$N����$nһ�����\n", me, obj);
				return 1;
			}
	                 COMBAT_D->do_attack(me, obj);
		}
	 	say(
"Ľ�ݸ�����" + obj->name() + "����˵�������书δ�ɣ��ͺø���Զ,\n"
"�㻹�ǰ�������ȥ��!\n"
		);
               this_player()->set_temp("marks/ʧ��", 1);
         }
	return 1;
} 

int ask_job()
{

        object me = this_player();
        object ob;
        mapping quest;
        mapping skl; 
        string *sname, place;        
        int i, skill = 0;
        quest = (__DIR__"lagjob")->query_quest();

        skl = me->query_skills();
        if ( !skl ) {
                tell_object(me, "��ȥѧһЩ�����Ȱɣ�\n");
                return 1;
                }
        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")

                        skill = skl[sname[i]];
                        
        if (skill < 80) skill = 80;

        if( me->query("family/family_name") != "����Ľ��")
           {
                      message_vision("$N����$n���һ�������ɵ��Ӳ������������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "�Ҵ��ഫ�������Ǻ��ѵģ��㻹�����߾���������");
                return 1;
}
    if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("$N����$nҡ��ҡͷ˵����Ȼ�����!\n", this_object(), me);
                      return 1;
            }
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵����Ȼ�����!\n", this_object(), me);
                      return 1;
            }
      if( (int)me->query_skill("shenyuan-gong",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }            
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ������Ǯ��û�У�����ô����Ҫ��ȥ�Ҵ��ഫ��������");
                return 1;
        }

        if (me->query("kill_mr") == 1) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "��Ϊ�������������̫���ˡ�");
                command("say " + me->query("id") + " ���ഫ�������ڡ�" + quest["short"]             + "�����֣���ȥ�ɣ�\n" NOR);
                me->set("kill_mr", 1);
                me->set("quest/quest_type", "Ѱ");
                me->set("quest/quest", "���ഫ������");
                me->set("task_time", time() + 310);
                me->apply_condition("menpai_busy",8);
                ob = new(__DIR__"qiangdao",1);
                if (me->query("combat_exp") > 2000000) {
                ob = new(__DIR__"qiangdao2",1);
                }
                ob->move(quest["place"]);
                 me->start_busy(3);
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp"));
                ob->set("max_force", me->query("max_force"));
                ob->set("eff_kee", me->query("max_kee"));
                ob->set("max_kee", me->query("max_kee"));
                ob->set("kee", me->query("max_kee"));
                ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);
                
                ob->set("force_factor", random(10));   
                return 1;
               }                              
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("kill_mr") == 1) {
                command("sigh");
                command("say ��������Ҳ���ұ���!");
                me->delete("kill_mr");
                 me->delete("kill_mr");
                me->apply_condition("menpai_busy",6);
                return 1;
                }
}



int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("��û�����������");        
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say ���ø�����������ƭ�ң�");
       return 0;
       }
   if(obj->query("id") == "mr yuxi" && obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say ��ҪǮ��ʲô?");
       return 0;
       }
   if(me->query("kill_mr") == 0 ){
       command("hehe "+(string)me->query("id"));
       command("say �������������û����ɰ���");
       return 1;
       }

   if(obj->query("id") == "mr yuxi" &&  obj->query("byname") !=me->query("name")) {
       command("pat " + me->query("id"));
       command("say �ⲻ�����ҵİɣ�");
       return 1;
       }

   if(obj->query("id") == "mr yuxi" && me->query("kill_mr") == 1)
   {
       command("nod "+(string)me->query("id"));
       command("say �ɵúã�\n");
       remove_call_out("destroying");
       call_out("destroying", 0, obj, ob, me);                       
       return 1;
       }
   else return 0;       
}

void destroying(object obj, object ob, object me)
{   
   object n_money;
   int kar, exp, pot;
   kar = random(me->query("kar")) * 15;
if (kar >300) kar=300;
if (kar <150) kar=150;
   exp = 480 + kar;
   pot = 400 + random(kar);

   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say �ף����أ�");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N��$n˵������������ü�Ϊ��ɫ���Ҿ�ָ�������ֹ����.\n"NOR,ob, me);
                  message_vision(HIC "\n����$N�ɹ����һش��ഫ����������������\n"
                + chinese_number(exp) + "��ʵս���飬\n"
                + chinese_number(pot) + "��Ǳ�ܣ�\n"
                + chinese_number(50) + "��������Ϊ��л��\n" NOR, me);
destruct(present("mr yuxi",ob));
                me->add("combat_exp", exp);
                me->add("potential", pot);
                me->add("score",50);
                me->delete("quest");
                me->delete("kill_mr");
   return;      
}