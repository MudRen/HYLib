#include <ansi.h>

inherit NPC;


void create()
{
        set_name("������", ({ "zhong zhaowen", "zhong", "zhaowen", "wen" }));
        set("long", @LONG
�������������۵��ϴ������ġ�ֻ��������
ɫ���鲼�·�����ñ��Ь���·�����¶��ëͷ��
���Ǹ����˸�ĸ��Т�ӷ�ɫ����ɫ�Ұף�����
�ֱ��ִ󣬱ǿ׳��죬���ŻҰ�С���ӡ�
LONG );
        set("nickname", HIR "��������" NOR);
        set("title", "���������ֵ�");
        set("gender", "����");
        set("age", 48);
        set("attitude", "peaceful");
        set("str", 23);
        set("int", 27);
        set("con", 25);
        set("dex", 24);

        set("qi", 14500);
        set("max_qi", 14500);
        set("jing", 13000);
        set("max_jing", 13000);
        set("neili", 13000);
        set("max_neili", 13000);
        set("jiali", 80);
        set("combat_exp", 1800000);
        set("score", 3000);

      set_skill("force", 160); 
        set_skill("lengyue-shengong", 160); 
        set_skill("dodge", 240); 
        set_skill("taxue-wuhen", 140); 
        set_skill("sword", 160); 
       
        set_skill("blade", 140); 

        set_skill("strike", 260); 
        set_skill("cuff", 260); 
        set_skill("tianchang-strike", 160); 
        set_skill("parry", 160); 
        set_skill("literate", 140); 
        set_skill("martial-cognize", 160); 


        set_skill("hujia-quan", 380); 
        

        map_skill("force", "lengyue-shengong"); 
        map_skill("dodge", "taxue-wuhen"); 

        map_skill("parry", "miaojia-jian"); 
        map_skill("strike", "tianchang-strike"); 
        map_skill("cuff", "hujia-quan"); 
        
        prepare_skill("strike", "tianchang-strike"); 
        prepare_skill("cuff", "hujia-quan"); 





        create_family("��ԭ���", 6, "����");

        setup();

        //carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 15);
}

void attempt_apprentice(object ob)
{
        command("hmm");
        command("say �߿����Ҳ���ͽ��");
}

