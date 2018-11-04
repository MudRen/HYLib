// suxingh.c
// shilling 97.2
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
mixed names = ({
        ({
        "xiangzhong","dongxian_ge","maipo_tang","bosi_xiaoqu","xiaoao_jianghu",
        "shanpo_yang","dielian_hua","caisang_zi","wusu_nian","dongxian_ge",
        "san_tai","yujie_xing","zuichui_bian","shuidiao_getou","yuanyuan_qu",                
        "wanghai_chao","wenshi_jian","yinma_changcheng","chunjiang_huayueye","jiangjin_jiu", 
        "yu_meiren","baixue_ge",
        }),
        ({
         "�α�","��å","ƫ��","�Խ�","����","С��","�к�","��ܽ","������",
		 "С��","����ϰ�","����ͨ","�","����","������","��С��","�α�",
		 "����ʦ̫","����ʦ̫","��Զ��","Ī����","½�˷�","������","��ҩʦ","��׺�",
		 "��Ұ��","����ţ","��־ƽ","С��Ů","���з�","ŷ����","������Ů","�������",
		 "����","������","������","������","����Ⱥ","�����","�����ʦ","���Ʊ���",
		 "��������","ׯ����","˫��","������","ľ����","��Զɽ","������","������",
		 "����","�ڰ���","������","������","�彣��","��ص���","����","����",
		 "��ɽͯ��","ΤһЦ","лѷ","�μ�","½�˷�","�Ŵ�ɽ","������","�������",
		 "ʯ����","���Ǻ�","��ң��","�쵤��","����","�ⲻƽ",
        }),
        });

int ask_job();
int ask_fail();
string ask_me();
string ask_lian();
string ask_book();
string ask_book2();
void create()
{
	set_name("���Ǻ�",({"su xinghe","su"}));
	set("gender", "����" );
	set("nickname", "�ϱ�����");
	set("shen_type", 0);
	set("class", "scholar");
	set("age",60);
	set("str", 55);
	set("con", 50);
	set("int", 55);
	set("dex", 55);
	set("per", 50);

	set("no_clean_up",1);

	set("long",
"���˾��Ǻųƴϱ����˵����Ǻӣ���˵�������Ʊ磬 \n"
"��һ�������е����ߣ��������书Ҳ��������֪��\n");

	set("combat_exp", 6500000);
	set("attitude", "peaceful");
	set("book_count", 1);
	set("chat_chance", 1);

	set("inquiry", ([
		"���ܵص�" :(:ask_me:),
		"�ؼ�"     :(:ask_book:),
		"����"     :(:ask_lian:),
		"����"     :(:ask_book2:),
                "����" : (: ask_job() :),
                "job" : (: ask_job() :),
                "ʧ��" : (: ask_fail() :),
	]) );

	set("max_qi", 15400);
	set("max_jing", 11400);
	set("neili", 39500);
	set("max_neili",39500);
	set("jiali", 60);
	set("env/wimpy", 60);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("blade", 250);
	set_skill("strike", 250);
	set_skill("sword", 250);
	set_skill("hand", 250);
	set_skill("qingyun-shou", 280);
	set_skill("panyang-zhang", 280);
	set_skill("liuyue-jian", 280);


	set_skill("lingboweibu", 280);
	set_skill("beiming-shengong", 280);
	set_skill("ruyi-dao", 300);
	set_skill("liuyang-zhang", 280);
	set_skill("zhemei-shou", 280);
	set_skill("literate", 100);

	map_skill("unarmed", "liuyang-zhang");
	map_skill("parry", "ruyi-dao");
	map_skill("blade", "ruyi-dao");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming-shengong");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");	
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.shishiruyi" :),
                (: perform_action, "blade.ruyi" :),
                (: perform_action, "dodge.lingbo" :),
                (: perform_action, "strike.zhong" :),
                (: perform_action, "strike.lianzhong" :),
                (: perform_action, "hand.tanmei" :),
                (: perform_action, "hand.zhemei" :),             
	}) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 300);
	create_family("��ң��", 2, "����");
	set("title","��ң�ɵڶ��������");
	setup();
	carry_object("d/xiaoyao/npc/obj/cloth")->wear();
	carry_object("d/xiaoyao/npc/obj/blade")->wield();
}


void attempt_apprentice(object ob)
{

	if (ob->query_int() < 30) {
		command("shake"+ ob->query("id")); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ����ѧ���϶��µ㹦��");
 return;
 	}

	command("say �ðɣ��Ҿ��������ˣ����Ҫ���Ŭ������");
	command("recruit " + ob->query("id"));
 }

string ask_book()
{
	object me,ob;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "��ң��")
	{
		return"��Ҫ�ؼ��͵ü�����ң�ɡ�";
	}
	command("sigh");
	return"���ɵ��书�ؼ�����һ�������ܵĵط�����Ҳûȥ����";
}
string ask_lian()
{
	object me,ob,ob1;
      string where;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "��ң��")
	{
		return"������ɵ��ӣ�����ѧʲô���գ�";
	}
if (ob->query_temp("singsong"))
	  return    HIW"�Ҳ��ǽ���ȥ��\n"+
           "          ��ϰ(chang)��\n"+
           "          һ��"+ob->query_temp("singsong")+"���׸���?"NOR; 


	  where=names[0][random(22)];
	  ob->set_temp("singsong",where);
	command("nod");
	  return    HIC"������ң�ɣ����������黭��\n"+
           "          ���ñ�����ȥ��ϰ(chang)��\n"+
           "          һ��"+where+"���׸�ɡ�"NOR; 
}

string ask_book2()
{
	object me,ob,ob1;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "��ң��")
	{
		return"��Ҫ���׾͵ü�����ң�ɡ�";
	}
	if (this_player()->query_temp("xys"))
		return "�Ҹո��������ֶ����ˡ�";

	command("nod");
	ob1 = new("/quest/menpaijob/xiaoyao/newjob/qupu");
	ob1->move(this_player());
	this_player()->set_temp("xys",1);

	return"�Ȿ��������ȥ�ðɡ�";
}

string ask_me()
{
	object me,ob;
	mapping fam; 
	ob=this_player();
	if (!(fam = ob->query("family")) 
		|| fam["family_name"] != "��ң��")
	{
		return"��Ҫ֪���ܵ��͵ü�����ң�ɡ�";
	}
	command("sigh");
	return"���ɵ��ܵ��ڻ�ɽ֮�ϣ����Ǽ��ա�������Ȥ����ȥ������";
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "scholar");
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

        if( me->query("family/family_name") != "��ң��")
           {
                      message_vision("$N����$n���һ�������ɵ��Ӳ������������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "�ұ��ɵ����������Ǻ��ѵģ��㻹�����߾���������");
                return 1;
}
      if( (int)me->query_skill("beiming-shengong",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
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
            
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ������Ǯ��û�У�����ô����Ҫ��ȥ�ұ��ɵ��������");
                return 1;
        }

        if (me->query("kill_xiaoyao") == 1) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "��Ϊ��ң�ɳ���������̫���ˡ�");
                command("say " + me->query("id") + " �߱�ָ�����ڡ�" + quest["short"]             + "�����֣���ȥ�ɣ�\n" NOR);
                me->set("kill_xiaoyao", 1);
                me->set("quest/quest_type", "Ѱ");
                me->set("quest/quest", "�߱�ָ��");
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
        
        if (me->query("kill_xiaoyao") == 1) {
                command("sigh");
                command("say ��������Ҳ���ұ��ɵ��߱�ָ��!");
                me->apply_condition("menpai_busy",12);
me->delete("kill_xiaoyao");
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
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say ��ҪǮ��ʲô?");
       return 0;
       }
   if(obj->query("id") == "zhi huan" && me->query("kill_xiaoyao") == 0 ){
       command("hehe "+(string)me->query("id"));
       command("say �������������û����ɰ���");
       return 1;
       }
  if(obj->query("id") == "zhi huan" && obj->query("byname") !=me->query("name")) {
       command("pat " + me->query("id"));
       command("say �ⲻ�����ҵİɣ�");
       return 1;
       }
   if(obj->query("id") == "zhi huan" && me->query("kill_xiaoyao") == 1)
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
   pot = 380 + random(kar);

   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say �ף����أ�");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N��$n˵������������ü�Ϊ��ɫ���Ҿ�ָ�������ֹ����.\n"NOR,ob, me);
                  message_vision(HIC "\n����$N�ɹ����һ��߱�ָ������������\n"
                + chinese_number(exp) + "��ʵս���飬\n"
                + chinese_number(pot) + "��Ǳ�ܣ�\n"
                + chinese_number(50) + "��������Ϊ��л��\n" NOR, me);
                me->add("combat_exp", exp);
                me->add("potential", pot);
                me->add("score",50);
                me->delete("quest");
                me->delete("kill_xiaoyao");
                destruct(present("zhi huan",ob));
   return;      
}