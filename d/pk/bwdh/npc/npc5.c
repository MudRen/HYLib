#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();
string ask_me();
int ask_zhou();

void create()
{
    set_name("С��ҩʦ", ({"huang yaoshi", "huang", "yaoshi"}));
    set("title", "�һ�����");
    set("nickname", HIY "��а" NOR );
    set("gender", "����");
    set("age", 42);
    set("long", 
        "�������һ����������ºö�ȫ�ɼ��ģ���˱��˳�������а����\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("chat_chance", 1);
    set("chat_msg", ({
        "��ҩʦ̾�˿����������� ���� �ض�������ĺ��ӣ���С��û���� ������\n",
        "��ҩʦ��ͷ��˼����Ȼ���\n",
    }));
    set("inquiry", ([
        "����"     : "���ֱ����Ů���Ĺ����� \n",
        "�����澭" : "������ܰ���ȡ���澭�ϲᣬ��һ������л�㡣\n",
    ]));

    set("qi", 5000);
    set("max_qi", 5000);
    set("jing", 3000);
    set("max_jing", 3000);
    set("neili", 13500);
    set("max_neili", 13500);
    set("jiali", 100);

    set("book_count", 1);
    set("combat_exp", 1500000);
    set("score", 0);
	 
    set_skill("leg", 300);             // �����ڹ�
    set_skill("force", 200);             // �����ڹ�
    set_skill("bibo-shengong", 300);     // �̲���
    set_skill("claw", 200);              // ����צ��
    set_skill("hand", 200);              // �����ַ�
    set_skill("finger", 200);            // ����ָ��
    set_skill("tanzhi-shentong", 300);   // ��ָ��ͨ
    set_skill("unarmed", 200);           // ����ȭ��
    set_skill("strike", 200);            // ����ȭ��
    set_skill("luoying-zhang", 300);     // ��Ӣ����
    set_skill("xuanfeng-leg", 300);      // ����ɨҶ��
    set_skill("dodge", 200);             // ��������
    set_skill("anying-fuxiang", 300);    // ��Ӱ����
    set_skill("parry", 200);             // �����м�
    set_skill("sword", 200);             // ��������
    set_skill("luoying-shenjian", 300);  // ��Ӣ��
    set_skill("yuxiao-jian", 300);       // ���｣��
    set_skill("lanhua-shou", 300);       // ������Ѩ��
    set_skill("qimen-wuxing",350);       // ��������
    set_skill("count",300);              // ��������
    set_skill("literate",300);           // ����ʶ��
	
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "xuanfeng-leg");
    map_skill("leg" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("parry"  , "yuxiao-jian");
    map_skill("sword"  , "yuxiao-jian");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "play" :),
                (: exert_function, "roar" :),
                (: perform_action, "dodge.taohaimangmang" :),
                (: perform_action, "hand.fuxue" :),
                (: perform_action, "sword.taohuajian" :),
                (: perform_action, "sword.taohuajian" :),
                (: perform_action, "sword.tianwai" :),                
                (: perform_action, "sword.yuxiao" :),                
                (: perform_action, "strike.shenjian" :),                
                (: perform_action, "strike.xuan" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "leg.kuangfeng" :),                
                (: perform_action, "finger.huayu" :),                
                (: perform_action, "finger.jinglei" :),                
                (: perform_action, "finger.lingxi" :),                
        }));
    set("inquiry", ([
        "�ؼ�" : (: ask_me :),
        "����ɨҶ�ȷ�" : (: ask_me :),
      	"�ܲ�ͨ": (: ask_zhou :),
    ]));


    create_family("�һ���", 1, "����");
    setup();
	
    carry_object("kungfu/class/taohua/obj/yuxiao")->wield();
    carry_object("kungfu/class/taohua/obj/bupao")->wear();
        carry_object(__DIR__"obj/jinchuang");
        carry_object(__DIR__"obj/jinchuang");        

//    carry_object("clone/book/jiuyin2");
    
}
