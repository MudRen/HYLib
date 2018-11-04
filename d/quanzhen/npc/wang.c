// wang.c ������
// By Lgg,1998.10

#include <ansi.h>

inherit NPC;

string ask_jiuyin();
string ask_zhipu();
string ask_duan();

void create()
{
        set_name("������", ({"wang chongyang", "wang"}));
        set("gender", "����");
        set("age", 66);
        set("class", "taoist");
        set("nickname",HIW"������"NOR);
        set("long",
                "������ȫ��̵Ŀ�ɽ��ʦ���״��ƽ������������ˡ�������Ʈ\n"
                "Ʈ�����ۻ��䣬üĿ��񳣬����Щ�ɷ���ǵ�ζ����������һ\n"
                "ǻ��Ѫ����Ч���������������ϧ��͢���ܣ������Ļ����䣬\n"
                "�ִӵ��¾����������������Ĵ�����ִ�ȫ��̡�\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 85);
        set("int", 85);
        set("con", 85);
        set("dex", 85);
        set("per", 85);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "hup" :),
                (: exert_function, "recover" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.jianqi" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.tonggui" :),                
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.qixinggongyue" :),
                (: perform_action, "unarmed.kong" :),
                (: perform_action, "unarmed.luanwu" :),                	
                (: perform_action, "unarmed.quan" :), 	
                (: perform_action, "unarmed.ming" :), 		
                (: perform_action, "unarmed.ruo" :),                	                	

                (: perform_action, "unarmed.dang" :),
                (: perform_action, "unarmed.shen" :),                	
                (: perform_action, "unarmed.fen" :), 	
                (: perform_action, "unarmed.hun" :), 		
                (: perform_action, "unarmed.jian" :),                	                	

                (: exert_function, "shield" :),                
                (: exert_function, "xiantiandafa" :),                
                (: exert_function, "powerup" :),                
        }));

        set("qi", 26500);
        set("max_qi", 26500);
        set("jing", 25400);
        set("max_jing", 25400);
        set("neili", 59000);
        set("max_neili", 59000);
        set("jiali", 100);

        set("combat_exp", 9000000);
        set("score", 500000);

        set_skill("force", 380);
        set_skill("xiantian-qigong", 390);    //��������
        set_skill("sword", 380);
        set_skill("quanzhen-jian",380);  //ȫ�潣
        set_skill("dodge", 260);
        set_skill("jinyan-gong", 380);   //���㹦
        set_skill("parry", 280);
        set_skill("unarmed",280);
        set_skill("haotian-zhang", 380);    //�����
        set_skill("array",380);
        set_skill("qixing-array",380);
set_skill("kongming-quan",380);
set_skill("qixing-jian",380);
set_skill("qixing-shou",380);
set_skill("hand", 300);
        set_skill("literate",220);
        set_skill("strike",350);
        set_skill("taoism",380);
        set_skill("finger",200);
        set_skill("sun-finger",200);  //һ��ָ
        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "xiantian-qigong");
        map_skill("strike", "haotian-zhang");
        map_skill("finger","sun-finger");
        map_skill("unarmed","kongming-quan");
if (random(2)==0)	        map_skill("unarmed","xiantian-qigong");
        //prepare_skill("finger","sun-finger");
        //prepare_skill("strike","haotian-zhang");

        create_family("ȫ���", 1, "�ƽ�");

        set("book_count",1);
        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
                "�����澭" : (: ask_jiuyin :),
                "һ��ָ" : (: ask_zhipu :),
                "�λ�ү" : (: ask_duan :),
        ]) );
	set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 250);
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/greenrobe")->wear();

}

void attempt_apprentice(object ob)
{
        if (ob->query_int() < 30) {
                command("say ������ʲ����������������Ǽ���ͽ��ѧϰ�ɡ�");
                return;
        }
        if ((int)ob->query_skill("xiantian-qigong",1) < 100 ) {
                command("say ��ı����ڹ��ķ������,�������Ը�������书��");
                return;
        }
        if ((int)ob->query("shen")<10000) {
                command("say �����������ұ�ѧ���˵Ļ���Ʒ�ʣ������ܶ���Щ����֮
�£���һ������Ϊͽ��\n");
                return;
        }
        command("say �ðɣ��������ʣ����ɴ����²����Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}

string ask_jiuyin()
{
        mapping fam;
        int lvl_force;

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "ȫ���")
                return RANK_D->query_respect(this_player()) +
                "�뱾�̺��޹ϸ��⻰�Ӻ�˵��";
        if (!(lvl_force = this_player()->query_skill("force",1))
            || lvl_force < 50)
                return RANK_D->query_respect(this_player()) +
                "�Ļ����ڹ�������֮ǳ��ǿ���澭�ϵ��ϳ��书�к����档";
        return "�����澭��������ѧ���ڣ����ѽ�����ʦ���ܲ�ͨ���ܣ�\n"
                +"����....�ڹ�Ĺ�ɵ�ʯ���ڣ��һ�����һЩͼ�Ρ�\n";
}

string ask_duan()
{
        object me=this_player();
        if(me->query_temp("tmark/ָ")==4) {
                me->add_temp("tmark/ָ",1);
                return("�λ�ү�ųơ��ϵۡ����Ҵ���һ��ָ��������������ָ����\n");
        }
        else {
                me->set_temp("tmark/ָ",0);
                return("���ʶλ�ү����ô��Ī��������Ϊ�ѣ�\n");
        }
}

string ask_zhipu()
{
        object ob,me=this_player();
        if(me->query_temp("tmark/ָ")==5) {
                me->set_temp("tmark/ָ",0);
                if(query("book_count")>0) {
                        ob=new("/clone/book/zhifapu");
                        ob->move(me);
                        add("book_count",-1);
                        return("�ðɣ���������࣬��־���ᣬ�Ȿָ���׾ͽ������ˡ�\n");
                }
                else
                        return("�������ˣ�ָ�����Ѿ�����ȡ���ˡ�\n");
        }
        else {
                me->set_temp("tmark/ָ",0);
                return  RANK_D->query_respect(me) +
                        "��������ҽ��������ɣ�\n";
        }
}
