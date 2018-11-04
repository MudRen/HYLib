//NPC:/d/lingshedao/npc/yinli.c
//Creat by Yjss on Sep.1999
#include "ansi.h"
inherit NPC;
inherit F_UNIQUE;
string ask_me();
int ask_popo();
void create()
{
        set_name(HIC"����"NOR, ({"yin li", "yin",}));
        set("nickname",HIW"ǧ������"NOR);
        set("long",
"�����ϼ������ף�����͹͹�����ü��ǳ�ª��\n"
"ֻ��һ�������������,���Ҳ�������.\n"
        );
        set("gender", "Ů��");
	set("attitude", "friendly");
        set("age", 16);
        set("shen_type", 1);
        set("per", 18);
        set("str", 120);
        set("int", 120);
        set("con", 125);
        set("dex", 120);

        set("max_qi", 5700);
        set("max_jing", 5500);
        set("neili", 50000);
        set("max_neili", 50000);
        set("jiali", 50);
        set_temp("no_kill", 1);
        set("combat_exp", 800000);
        set("score", 50000);
	set("book_count", 1);
        set_skill("force", 280);
        set_skill("dodge", 260);
        set_skill("parry", 260);
        set_skill("unarmed",290);
        set_skill("hand",290);
        set_skill("xiaoyao-bu",350);
        set_skill("qianzhu-wandushou",350);
        map_skill("unarmed","qianzhu-wandushou");
        map_skill("parry", "qianzhu-wandushou");
        map_skill("dodge","xiaoyao-bu");
        map_skill("force","shenghuo-shengong");
        
        set("inquiry",([
               "���޼�" : "�����ú�Ӣ�������ǽ����úܡ���Ҫ��������ȥ,
һ���Ӹ�����һ�������ϣ���Ҳ���ˣ���֪������,
����,����ҧ��������Ѫ���졣���Ҿ�����������!\n",
               "��ĸ": "������������Ҫ�ң������Ҿͻ�ɱ�ҡ����������Һ�����.\n",
               "���": "����ô֪����?���߿�,��Ȼ���㳢���ҵ�ǧ�����ֵ�����!\n",
               "������" : (: ask_popo :),
		"����":(:ask_me:),
           ]) );

          setup();
          carry_object("/clone/cloth/female1-cloth")->wear();
          carry_object("/d/yanziwu/npc/obj/flower_shoe")->wear();
          carry_object("/d/yanziwu/npc/obj/necklace")->wear();
}             
void init()
{
  add_action("do_quit","exert");
}


int ask_popo()
{
        object ob=this_player();
        message_vision("�������$N�����˵:�㲻����,�����ϴ�����.˵��
���������˴���.\n",ob);
        ob->move("/d/taohua/dahai");
        tell_object(ob,BLU"���ں��Ϻ����˺ܾúܾ�.......\n" NOR );
        call_out("goto_lingshedao",10,ob);
        return 1;
}

void goto_lingshedao(object ob)
{
        tell_object(ob,"�����ڿ�����һ�����ĺ�̲��.����������´�,Ȼ��
�﷫����ʻȥ.\n");
        ob->move("/d/lingshedao/haitan1");
}

string ask_me()
{
	object me,ob;
	ob=this_player(); 

	if (query("book_count") < 1)
		return "�������ˣ��������Ѿ����͸������ˡ�";   
	add("book_count", -1);                  

	message_vision(HIY"����ӻ����ó�һ�����У����˸�$N \n\n"NOR,ob);
	me=new("/clone/book/jinhe");
	me->move(ob);

	return "���������Ҫ�úñ��ܡ�\n";
}

int do_quit(string arg)
{
	if(arg=="roar") {
        write(this_player()->query("name")+"�����ﲻ����roar�ɣ�\n");
        return 1;
	}
}