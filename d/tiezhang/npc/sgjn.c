// qqren.c �Ϲٽ���
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_qiubai();
int ask_wumu();
int ask_dongxi();
int ask_xinyuan();
int ask_jueji();
int ask_baowu();

object who = this_player();


void create()
{
    set_name("�Ϲٽ���", ({ "shangguanjiannan", "shang", "shangguan", "jiannan"}));
    set("nickname", "����ˮ��Ư");
	set("long", 
        "��λ�Ϲٰ�������һλ����֮ʿ�����ư��������κ��������٣�������\n"
        "��֮�£������������ƴ����ڽ�������Ѱ�ѿ����뱱����ؤ���ͥ�����ˡ�ֻ�Ǻ�����\n"
        "Ȼ�����伣����֪�����ˡ�\n");
	set("gender", "����");
	set("age", 80);
    set("attitude", "peaceful");
	set("shen_type", 1);
        set("str", 75);
	set("int", 70);
	set("con", 78);
        set("dex", 74);
	
	set("max_qi", 36000);
	set("max_jing", 36000);
	set("neili", 56000);
	set("max_neili", 56000);
	set("jiali", 200);
	set("combat_exp", 9500000);
	set("score", 500000);

	set_skill("force", 280);
	set_skill("guiyuan-tunafa", 380);
	set_skill("dodge", 300);
	set_skill("strike", 300);
	set_skill("hammer", 380);
	set_skill("axe", 380);
	set_skill("shuishangpiao", 380);
	set_skill("strike", 350);
	set_skill("tiezhang-zhangfa", 380);
	set_skill("parry", 200);
	set_skill("cuff", 300);
	set_skill("literate", 100);
	set_skill("tiexue-hammer",380);
	set_skill("duanyun-fu", 380);
	set_skill("tongbi-zhang", 380);
	set_skill("xuanyuan-axe", 380);
	set_skill("liumang-quan", 380);
		
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("cuff", "liumang-quan");
	map_skill("parry", "xuanyuan-axe");
	map_skill("axe", "xuanyuan-axe");
	prepare_skill("strike", "tiezhang-zhangfa");
	prepare_skill("cuff", "liumang-quan");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.pofuchenzhou" :),
                (: perform_action, "cuff.guguoshenyou" :),
                (: perform_action, "cuff.luori" :),
                (: perform_action, "axe.kaitianpidi" :),
                (: perform_action, "axe.sanbanfu" :),
                (: perform_action, "axe.jiuqipoxiao" :),
                (: perform_action, "axe.jiuqipoxiao" :),                	
                (: perform_action, "axe.jiuqipoxiao" :),                	                	
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
		(: command("unwield bigaxe") :),
		(: command("wield bigaxe") :),			
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
            set("inquiry", ([
"name" : "�Ϸ����Ϲ٣������ϡ��������ư�ĵ�ʮ����������\n",
"here" : "��ǧ��Ϊ�˽��������������ص�������ɽ�����������ʯ�ң��ߣ�\n",
"��������Ķ���" : (: ask_dongxi :),
"��������" : (: ask_wumu :),
"��Ը" : (: ask_xinyuan :),
"����" : (: ask_jueji :),
"����" : (: ask_baowu :),
        ]));
        set("chat_chance", 1);
        set("chat_msg", ({
"�Ϲٽ���ŭ���������Ϸ�����ؼ����գ���Ҫ������������Ķ�����ʬ��Σ�����\n",
"�Ϲٽ���̾����������֪�������������ںδ��������˵���ѽ��������\n",
        }) ); 

    create_family("���ư�", 13, "����");


	setup();
carry_object(__DIR__"obj/axe")->wield();
	carry_object(__DIR__"obj/black-cloth")->wear();
}

/*void attempt_apprentice(object me)
{
        if ((int)me->query("shen") < 50000) {
                command("hehe");
                command("say ���Ϲٽ��Ͽɲ����ĵز���������ͽ�ܡ�");
                return;
        }
                command("say �ðɣ��Ҿ��������ˡ�ϣ������������񹦣���֮������");
                command("recruit " + me->query("id"));
}*/

//int recruit_apprentice(object ob)
//{
//        if( ::recruit_apprentice(ob) )
//                add("apprentice_available", -1);
//}
void attempt_apprentice(object ob)
{
         if ((int)ob->query("shen") <=10000) {
                command("shake");
                command("say ��Ŀ¶�׹⣬�������֮��������������֮�ˣ��㻹�ǻ�ȥ�ɣ�");
                return;
        }
         if ((int)ob->query_skill("guiyuan-tunafa", 1) < 140) {
                command("shake");
                command("say ���ư���书�����Թ�Ԫ���ŷ�Ϊ�����ģ�");
                command("say ��Ļ�������δ���ã�������ûʲô���Խ���ģ�");
                command("sigh");
                return;
        }
          if ((int)ob->query_skill("tiezhang-zhangfa", 1) < 140) {
                command("shake");
                command("say �����Ʒ����Ұ���������");
                command("say ��Ļ�������δ���ã�������ûʲô���Խ���ģ�");
                return;
        }
          if ((int)ob->query_temp("mark/����")) {
                command("say �ðɣ��Ҿ��������ˡ�ϣ���㲻Ҫ����ʧ����");
                command("recruit " + ob->query("id"));
                command("say ����������ҵ����£��͵��̿���ϰ���ƾ������Ұ�\n"
                        "��ɽ�����������������ԭ�����ľ��������Ʒ��������䲻������\n"
                        "ʮ���ƣ������Ʒ�����������ڽ���ʮ����֮�ϡ�");
                command("haha");
                command("look " + ob->query("id"));
                command("hmm");
                command("say ��������Ʒ��������㲻������δ�����衣���Ƶ�\n"
                        "�������ڣ�����Ҫ���Ԫ���ŷ����ϣ���ս���У�����ʹ��һ�о�\n"
                        "���������������������������ף��޼᲻�ݡ�");
                command("pat " + ob->query("id"));
                command("say ����Ϊʦ�ͽ��˾����������㣡");
                }
                else
                {
                command("say �Ϸ�һֱ�ܵ���������飬���ܷ�ȥ�����������ң�\n");
                return;
        }
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
            ob->set("title", HIM"���ư��Ϲٰ�������"NOR);
        ob->set("class","brigand");
}
int ask_dongxi()
{
command("say ������ǧ�����������ĵ��ӣ�������������һ���������Ҳ���ޱ���\n"
"���������ڣ��������Ұ�����ܴ����²���������������ʢ��������δ��ã���Ҫѧ����\n"
"�ľ���������������δ�̣�����δ�Ӵ��ڡ�����˻������ģ���Ϊ�Ϸ��˽������Ϸ��\n"
"��֮�ʣ�����˫�ȴ�ϣ��������������ùǣ��������ʯ��֮�У����Ϸ򽫾�������������\n");
command("sigh");
return 1;
}

int ask_jueji()
{
command("say �����������--����������ս����perform tianlei�������ͷų��޼᲻��\n"
"����������߷������ˣ�ʮ�ְԵ���\n");
return 1;
}

int ask_wumu()
{
    object ob;
    ob = this_player();

if ( !present("zitie", ob)) 
{
command("say �ٺ٣�����������������ǹ�ϵ�����������Ĵ��£�������ܷ��ĸ����㣿\n");
return 1;
}
else 
{
command("look " + ob->query("id"));
command("say ��λ" + RANK_D->query_respect(ob) + "��Ȼ���������졷�������������ұ������ˣ��ðɣ��Ϸ��\n"
"������������¸�����ɣ�\n");
command("say �������������������������µ�һ�����������м������о����̵�Ҫ����\n"
"�Ϸ������Ǻ����ҽ����Ĳ��£�������������һ��֮�£����Ϊ�ܣ������������ư\n"
"���������˵�ⲿ������ڻʹ�֮�У��;�����и��֣�����͵�˻��������뽫֮����һ\n"
"�����İ����Ľ��졣���������Һ�Ȼ����ޱ䣬�����ԸҲδ�ܴ�ɡ�\n");
this_player()->set_temp("marks/����1", 1);
return 1;
}
}

int ask_xinyuan()
{
if ((int)this_player()->query_temp("marks/����1")) {
command("say �Ϸ���������һ��ɽˮ�������а����ŷ�����ĵص㣬�ҽ��⸱��������\n"
"ţ�Ҵ�,��������ҵ��⸱�����Ϳ��԰�������ָ��ȥ�����������ˡ�\n");
this_player()->set_temp("find_shanshui", 1);
return 1;
}
else{
command("say �Ϸ�ȴ�и�δ�˵���Ը�������ܸ����㣡\n");
return 1;
}
}

int accept_object(object who, object ob)
{
        //object who;
        who = this_player();

        if ((string)ob->query("name")=="���������项") {
             
                command(
"say ������������Ҫ�ҵ��������飬�Ȿ�������ؼ����գ������ϲ����۰���\n"
"������һ��Ȿ�飬�Ҳ��������ģ�\n");

                this_player()->set_temp("mark/����", 1);
        return 1;
                }
else return 0;          

}

int ask_baowu()
{
        object me  = this_player();
        mapping fam = me->query("family");

        if(!fam || fam["family_name"] != "���ư�"){
                command("say "+RANK_D->query_respect(me) + "�뱾��������������֪�˻��Ӻ�̸��");
                return 0;
                }

         if(fam["master_name"] != "�Ϲٽ���" ){
                command("say ����ʲô���������ҹ���ȥ! ");
                write(HIY"һ�ɾ޴��������ӭ�������������Ƴ���ʯ��"NOR);
                me->move("/d/tiezhang/wmfeng");
                return 1;
                }
         else{
         command("say ���������ֻ�����㣬����������");
         write("�����ڵڶ�ָ�ڵĶ�Ѩ�\n");
         me->set_temp("marks/baowu", 1);
         return 1;
         }
}
