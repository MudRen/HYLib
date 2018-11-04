// hetaichong.c (kunlun)
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_ding();
string ask_su();
int ask_job();
int ask_fail();


void create()
{
	set_name("��̫��", ({ "he taichong", "he" }));
	set("title", "����������");
	set("nickname", "��������");
	set("long",
		"���������������š����ｭ��������������̫�塣\n"
		"��Ȼ����Ѵ󣬵���Ȼ���ó�������ʱӢ��������\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 55);
	set("int", 55);
	set("con", 55);
	set("dex", 55);

	set("max_qi", 22500);
	set("max_jing", 22000);
	set("neili", 43000);
	set("max_neili", 43000);
	set("jiali", 50);
	set("combat_exp", 8200000);
	set("score", 40000);

	set_skill("taiji-shengong", 180);
	set_skill("art", 280);
	set_skill("literate", 200);
	set_skill("force", 200);
	set_skill("xuantian-wuji", 320);
	set_skill("dodge", 240);
	set_skill("taxue-wuhen", 320);
	set_skill("strike", 320);
	set_skill("kunlun-zhang", 320);
	set_skill("parry", 265);
	set_skill("sword", 275);
	set_skill("liangyi-jian", 325);
	set_skill("xunlei-jian", 325);
	set_skill("mantian-huayu", 325);
	set_skill("throwing", 160);
	set_skill("cuff", 155);
	set_skill("zhentian-quan", 320);
set_skill("qixian-jian", 320);
	set_skill("goplaying", 280);
	set_skill("luteplaying", 280);

        set_skill("finger", 180);
	set_skill("hand", 180);	
	map_skill("throwing", "mantian-huayu");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("cuff", "zhentian-quan");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
	prepare_skill("leg", "chuanyun-tui");
	prepare_skill("strike", "kunlun-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                                (: perform_action, "sword.hebi ban" :),
            		(: command("perform sword.hebi ban") :),
                                (: perform_action, "sword.hebi ban" :),
            		(: command("perform sword.hebi ban") :),            			
                (: perform_action, "strike.diezhang" :),
                	(: perform_action, "throwing.huayu" :),
                 	(: perform_action, "strike.liuyun" :),
(: perform_action, "strike.yixing" :),  
                (: command("unwield qin") :),
                (: command("wield qin") :),
                (: perform_action, "sword.jianqin" :),
                (: perform_action, "sword.ren" :),
                (: perform_action, "sword.feixue" :),
                (: perform_action, "sword.juedi" :),
                (: perform_action, "parry.tianwaifeiyin" :),
        }) );

	create_family("������", 4, "������");
	set("class", "taoist");

	set("inquiry",
		([
			"�ķ�" : (: ask_me :),
			"��ϰ֮" : (: ask_su :),
			"׷ɱ" : (: ask_ding :),
		                "����" : (: ask_job() :),
                "ʧ��" : (: ask_fail() :),
                "job" : (: ask_job() :),
                "fail" : (: ask_fail() :),

		]));
		

	set("book_count", 1);
	set("ding_count", 18);

	setup();
	carry_object("/d/kunlun/obj/sword.c")->wield();
	carry_object("/d/kunlun/obj/pao2.c")->wear();
}

void attempt_apprentice(object ob)
{
/*	 if((int)ob->query("shen")<0){
	 command("say ���������������������ɣ�"+RANK_D->query_respect(ob)+
				"��Ʒ��ʵ�����˻��ɡ�");
	 command("say "+RANK_D->query_respect(ob)+
				"�����Ȼ�ȥ�������°ɡ�");
	 return;
	 }
*/
	 if(ob->query("gender")=="Ů��"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"�Ϸ�ɲ�����Ů���ӣ���ȥ���ҷ���ȥ�ɡ�");
	 return;
	 }

//          if(ob->query("appren_hezudao", 1) == 1) {
//	 command("say ǰ�����ҿ������Ц��������ɱ�������ˡ�");
//	 return;
//	 }
    
	if(ob->query_skill("xuantian-wuji",1)<100){
	 command("hmm");
	 command("say "+RANK_D->query_respect(ob)+
				"��������޼���̫��ҿɲ������㡣");
	 return;
	 }
	 command("say �ðɣ��ұ������㣬ֻ����Ͷ��������֮����ð���ѧ�ա�");
	 command("recruit " + ob->query("id"));
}


string ask_me()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "������")
					 return RANK_D->query_respect(this_player()) +
					 "�뱾��������������֪�˻��Ӻ�̸��";
		  if (query("book_count") < 1)
					 return "�������ˣ������ľ��ѱ���ʦ�������ˡ�";
//          if(ob->query("gender")!="Ů��"||ob->query("per")<23)
//        	     	 return "�����ľ����������";
	 	  add("book_count", -1);
		  ob = new("/d/kunlun/obj/force-book.c");
		  ob->move(this_player());
		  return "�������б����ķ��������й����������ģ����û�ȥ�ú����У��пն�������Ŷ";
}

string ask_ding()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "������")
					 return RANK_D->query_respect(this_player()) +
					 "�뱾��������������֪�˻��Ӻ�̸��";
		
		 if(this_player()->query_skill("mantian-huayu",1) < 60)
           return "�������ԸΪʦ��Ч����������ƽʱһ�����࣬����ȥ��";
		   
	if ( present("sangmen ding", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ���������ô����Ҫ�ˣ�";
		  if (query("ding_count") < 1)
					 return "ɥ�Ŷ��Ѹ�������ȥ׷ɱ��ϰ֮���ˣ���Ͳ���ȥ�ˡ�";
		  add("ding_count", -1);
		  this_player()->set_temp("kunlun/ding",1);
		  ob = new("/d/kunlun/obj/sangmending.c");
		  ob->move(this_player());
		  return "�������ԸΪʦ��Ч����������ƽʱһ�����࣬���ɥ�Ŷ������ȥ�ɡ�";
}
string ask_su()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "������")
					 return RANK_D->query_respect(this_player()) +
					 "�뱾��������������֪�˻��Ӻ�̸��";
		
		 if(this_player()->query_temp("kunlun/ding",1))
           return "�㻹����������ʲô��������ȥ׷��ϰ֮";
		  return "��ϰ֮��һﾹȻ��͵�����ɵ������񽣣����ɵ��ӱص�����׷ɱ��";
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

        if( me->query("family/family_name") != "������")
           {
                      message_vision("$N����$n���һ�������ɵ��Ӳ������������������ļ�ϸ��\n", this_object(), me);
                      return 1;
            }

           if (me->query("combat_exp") < 100000) {
                command("say " + RANK_D->query_respect(me) + "�㻹�����߾���������");
                return 1;
}
   if ((int)me->query_condition("guojob2_busy"))
            {
                      message_vision("��̫�����$Nҡ��ҡͷ˵����Ȼ�����!\n", me);
                      return 1;
            }

        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N����$nҡ��ҡͷ˵����Ȼ�����!\n", this_object(), me);
                      return 1;
            }
            
        if (me->query("potential") < 200 || me->query("combat_exp") < 300) {
                command("say ������Ǯ��û�У�����ô����Ҫ��ȥ�����Ұ�檲���ҩ��");
                return 1;
        }
      if( (int)me->query_skill("xuantian-wuji",1) < 50)
            {
                message_vision("$N����$n���һ������ı����ڹ�������\n", this_object(), me);
                return 1;
            }

        if (me->query("kill_kunlun") == 1) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "������һ����Ұ�檲���ҩ���Һúú�лл��ġ�\n");
                command("say " + me->query("id") + "������ͽ����ҩ�ڡ�" + quest["short"]  + "�����֣���ȥ�ɣ�\n");
                me->set("kill_kunlun", 1);
                me->set("quest/quest_type", "Ѱ");
                me->set("quest/quest", "��ҩ");
                me->set("task_time", time() + 310);
me->apply_condition("menpai_busy",8);
                ob = new(__DIR__"qiangdao",1);
                if (me->query("combat_exp") > 2000000) {
                ob = new(__DIR__"qiangdao2",1);
                }
                ob->move(quest["place"]);
                ob->set_temp("owner/id",me->query("id"));
        ob->set("qi", me->query("max_qi")* 4 / 5);
        ob->set("eff_qi", me->query("max_qi")* 4 / 5);
        ob->set("max_qi", me->query("max_qi")* 4 / 5);
        ob->set("jing", me->query("max_jing")* 4 / 5);
        ob->set("eff_jing", me->query("max_jing")* 4 / 5);
        ob->set("max_jing", me->query("max_jing")* 4 / 5);
        ob->set("neili", me->query("neili")* 4 / 5);
        ob->set("max_neili", me->query("max_neili")* 4 / 5);
                
                ob->set("force_factor", random(10));   
me->start_busy(3);
                return 1;
               }                              
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("kill_kunlun") == 1) {
                command("sigh");
                command("say �����Ұ�檵Ĳ�....����80��POT.");
                me->apply_condition("menpai_busy",6);
me->delete("kill_kunlun");
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
   if(obj->query("byname") !=me->query("name")) {
       command("pat " + me->query("id"));
       command("say ���ҩ�������ҵİɣ�");
       return 1;
       }

   if(me->query("kill_kunlun") == 0 ){
       command("hehe "+(string)me->query("id"));
       command("say �������������û����ɰ���");
       return 1;
       }

   if(obj->query("id") == "qi yao" && me->query("kill_kunlun") == 1)
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
   exp = 500 + kar;
   pot = 350 + random(kar);
   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say �ף����أ�");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N��$n˵������������ü�Ϊ��ɫ���Ҿ�ָ�������ֹ����.\n"NOR,ob, me);
                  message_vision(HIC "\n����$N�ɹ����һ�������Ҫ����ҩ����������\n"
                + chinese_number(exp) + "��ʵս���飬\n"
                + chinese_number(pot) + "��Ǳ�ܣ�\n"
                + chinese_number(50) + "��������Ϊ��л��\n" NOR, me);
                me->add("combat_exp", exp);
                me->add("potential", pot);
                me->add("score",50);
                me->delete("quest");
                me->delete("kill_kunlun");
                destruct(present("qi yao",ob));
   return;      
}