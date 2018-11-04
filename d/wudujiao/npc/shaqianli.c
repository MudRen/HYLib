// shaqianli.c
// ɳǧ��
// amber
#include <ansi.h>
inherit NPC;
string ask_job();
int do_task(string arg);

void create()
{
        set_name("ɳǧ��", ({ "sha qianli", "sha" }));
        set("nickname", HIG "����" NOR);
        set("long",@LONG
�������嶾�̵Ļ�������ɳǧ���Ŀ��࣬���������ڽ���ת����ļ
���ڣ����ڵ����ǵ����Ź���
LONG
        );
        set("title","�嶾�̻�������");
        set("gender", "����");
        set("age", 32);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 11000);
        set("max_jing", 11000);
        set("neili", 11000);
        set("max_neili", 11000);
        set("jiali", 40);
        set("combat_exp", 1200000);
        set("score", 5000);

        set_skill("force", 170);
        set_skill("wudu-shengong", 180);
        set_skill("dodge", 170);
        set_skill("wudu-yanluobu", 180);
        set_skill("unarmed", 80);
        set_skill("qianzhu-wandushou", 180);
        set_skill("parry", 180);
        set_skill("sword", 170);
        set_skill("wudu-goufa", 180);
        set_skill("poison", 180);
        set_skill("literate", 160);
	set_skill("shedu-qiqiao",180);
	set_skill("finger",180);
//        set_skill("hammer", 60);
//        set_skill("jinshe-chui", 70 );
//      set_skill("strike", 200 );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
	map_skill("poison","shedu-qiqiao");
        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
//        map_skill("hammer", "jinshe-chui");

        create_family("�嶾��", 13, "��������");

        setup();
        set("inquiry", ([
                        "Ѳɽ" : (: ask_job :),
                       ]));

        carry_object("/d/wudujiao/obj/ganggou")->wield();
        carry_object("/d/city/obj/cloth")->wear();

        add_money("silver",10);
}

void attempt_apprentice(object ob)
{

                  if ((string)ob->query("gender") == "����") {
                                 command("say ��λ������Ҫ����Ц�ˡ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "���ǿ�ȥ�ź���ϰɣ�");
                return;
                  }

                  if ((int)ob->query("shen") > 1000) {
                                 command("say �����嶾�̵��ӱ����ĺ�������");
                command("say �ҽ̵��ӹ�����������������α����");
                return;
                  }


//          command("chat �ٺٺٺ٣���������");
//          command("chat �õ����嶾�̷����󣬳ư�����ָ�տɴ��ˡ�");
//          command("chat �ٺٺٺ٣���������");
        command("recruit " + ob->query("id"));
        ob->set("class", "none");
         ob->set("title","�嶾��ͽ");
}


void init()
{
        add_action("do_task","task");
}


string ask_job()
{
        mapping fam;

        object me;
        object ob;
        ob=this_player();
        me=this_object();
 if (!(fam = this_player()->query("family"))
                 || fam["family_name"] != "�嶾��")
                                         return RANK_D->query_respect(this_player()) +
                "���㲻���嶾�̵ĵ��ӣ��˻��Ӻ�˵��";
        if (ob->query_temp("xunshan"))
                return ("�㲻���Ѿ�����Ѳɽ�������𣿻�����ȥ����\n");
        if (ob->query("combat_exp")<5000)
                return ("���书̫�ͣ��޷�ʤ��!��\n");
        if (ob->query("combat_exp")>=100000)
        return ("�ҿ�����书�����൱�Ĺ����ˣ��Ͳ���������������ˣ�ȥ�����˹�������ɡ�\n");
        ob->set_temp("xunshan",1);
             ob->apply_condition("wudu_xunshan2",random(6)+9);;
        return "�ðɣ�����ڱ�����Χ�Ĵ��鿴һ�£�ѲɽʱӦ��С�ķ�������ֹ��С�";
}

int do_task(string arg)
{
        object ob,me;
        int pot,exp,sco,sil;
        ob=this_player();
        me=this_object();
        if(!(arg||arg=="ok")) return 0;
    if(!ob->query_temp("xunshan")) 
            return notify_fail("��ûѲɽ������ʲô����\n");
    if (interactive(ob)&&(int)ob->query_condition("wudu_xunshan2")) {
                 command("angry "+ob->query("id"));
                 return notify_fail(RED "����ô������ˣ��ǲ�����Щ�ط�ֻ��������������\n"NOR);
                 }          
        if(!(ob->query_temp("wudu_xs/huayuan1")
&&ob->query_temp("wudu_xs/huayuan2")&&ob->query_temp("wudu_xs/huayuan3")))
            return notify_fail("���ǲ���͵������԰©��Щ�ط�ûѲ�� \n");
        if(!(ob->query_temp("wudu_xs/huating1")
&&ob->query_temp("wudu_xs/huating2")&&ob->query_temp("wudu_xs/huating3")))
            return notify_fail("���ǲ���͵��������©��Щ�ط�ûѲ�� \n");
        if(!(ob->query_temp("wudu_xs/beiyuan")
&&ob->query_temp("wudu_xs/chufang")&&ob->query_temp("wudu_xs/bingqi")))
            return notify_fail("���ǲ���͵������Ժ©��Щ�ط�ûѲ? \n");
        if(!(ob->query_temp("wudu_xs/damen")
&&ob->query_temp("wudu_xs/jingshi")&&ob->query_temp("wudu_xs/shufang")        
&&ob->query_temp("wudu_xs/lianwu")&&ob->query_temp("wudu_xs/dating")))
            return notify_fail("���ǲ���͵��������©��Щ�ط�ûѲ? \n");    
        if(!(ob->query_temp("wudu_xs/nanyuan")
&&ob->query_temp("wudu_xs/liandu")&&ob->query_temp("wudu_xs/xiangfang")
&&ob->query_temp("wudu_xs/yaoshi")))
            return notify_fail("���ǲ���͵������Ժ©��Щ�ط�ûѲ? \n");    
        if(arg=="ok")
        {
                command("pat "+ob->query("id"));
                command("say ����������Ϊ���ˣ�"+RANK_D->query_respect(ob)+"�������úã�");
        sil=(int)(ob->query_skill("force",1)/10)+random(5);
             pot=30+random(50);
             sco=30+random(50);
            exp=random(50)+random(100);
        me->add_money("silver",sil);
        command("give "+ob->query("id")+" "+sil+" silver");
              ob->add("potential",pot);
              ob->add("combat_exp",exp);
              ob->add("wudu_job",1);
                          tell_object(ob,HIW" �㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       chinese_number(sil)+"������\n"+
                       "��Ϊ�嶾������"+ob->query("wudu_job")+"�ι�����\n"
                       NOR);
                      ob->delete_temp("xunshan");
              ob->delete_temp("wudu_xs");
                return 1;
        }
        return 1;
}

