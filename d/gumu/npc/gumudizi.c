// longnv.c С��Ů

// 1998.9 by Lgg

#include <ansi.h>

inherit NPC;
string* nm1 = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��",
"��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��",
"��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��",
"Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��",
"��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��",
"��","��","֧","��","��","��","¬","Ӣ","��","��","��","˧",
"˾��","�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�",
"ξ��","����","�̨","����","����","���","����","����","̫��",
"����","����","����","ԯ��","���","����","����","����","Ļ��",
"˾ͽ","ʦ��","��","��ľ","����","����","���","����","����",
"����","��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��",
"��ǧ","����","����","�Ϲ�","����","�麣","����","΢��","����",
"����","����","����","����","�Ϲ�",
"��","��","��","��","��","��","��","Ĳ","��","��","ī","��",
"��","��","��","��","١","��","��","��","��","��","��","��",
"��","ʯ",
});

string* id = ({
"zhao","qian","sun","li","zhou","wu","zhen","wang","feng","chen","zhu","wei",
"jiang","shen","han","yang","zhu","qing","you","xu","he","lu","shi","zhang",
"kong","cao","yan","hua","jin","wei","tao","jiang","qie","xie","zhou","yu",
"bo","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang",
"lu","wei","chang","ma","miao","feng","hua","fang","sha","ren","yuan","liu",
"deng","bao","shi","tang","fei","lian","chen","xue","lei","he","ni","tang",
"teng","yin","luo","hua","hao","wu","an","chang","le","dai","shi","fu",
"pi","bian","qi","kang","wu","yu","yuan","po","gu","ying","ping","huang",
"he","mu","xiao","yin","yao","shao","zhan","wang","qi","mao","yu","di",
"mi","bei","ming","zang","ji","fu","cheng","dai","tan","song","mao","pang",
"xiong","ji","su","qu","xiang","zhu","dong","liang","fan","hu","ling","ho",
"yu","wan","zhi","ke","jiu","guan","lu","ying","qiu","hou","yue","suai",
"sima","shangguan","ouyang","xiahou","zhuge","wenren","dongfang","helian","huangpu",
"weichi","gongyang","zhantai","gongye","zongzheng","puyang","chunyu","shanyu","taishu",
"shentu","gongshun","zhongshun","xuanyuan","linghu","zhongli","yuwen","changshun","murong",
"situ","shikong","zhuankong","duanmu","wuma","gongxi","qidiao","lezheng","xiangsi",
"gongliang","tuozhi","jiagu","zaifu","guliang","chujing","yanfa","ruye","tuqin",
"duanqian","baili","dongguo","nanguo","huyan","guihai","yangshe","weisheng","liangqiu",
"zuoqiu","dongmen","ximen","baishang","nangong",
"gou","kang","kuang","hou","you","qing","shang","mo","she","er","mo","ha",
"qiao","nian","ai","yang","dong","di","wu","yan","fu","kai","zong","zong",
"lin","shi",
});

string* nm2 = ({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm4 = ({      //Ů��ר��
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","�","��","��","��","��","��","��","��","��",
"ٻ","Ƽ","��","ϼ","��","��","��","Ӣ","��","��","��",
"��",
});


void create()
{
      string weapon;
   int i = random(sizeof(nm1));

   set_name(nm1[i]+nm2[random(sizeof(nm2))]+nm4[random(sizeof(nm4))], ({id[i]}));
        set("gender", "Ů��");
        set("age", 18);
        set("long",
                "����һϮ��ɴ��İ��¡�\n"+
                "�ǹ�Ĺ����һ����Ů���ӡ�\n");
        set("attitude", "friendly");

        set("per", 30);
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);

        set("chat_chance", 1);
        set("chat_msg", ({
                (: command, "say ��Ĺ���峾���ף������Ļ������Կ�"BRED"(help gumu)"NOR"��" :),
                (: command, "say ��˵ʦ�磬ʦ�����Ѿ���Ϊ��������µĴ��ˣ� ʲ��ʱ���ܴ���ȥ�����أ�" :),
        }) );

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),
        }) );

        set("qi", 2500);
        set("eff_qi", 2500);
        set("max_qi", 2500);
        set("jing", 2600);
        set("eff_jing", 2600);
        set("max_jing", 2600);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 200);

        set("combat_exp", 700000);
        set("score", 0);

        set_skill("force", 150);
        set_skill("throwing", 100);
        set_skill("whip", 160);
        set_skill("yinsuo-jinling", 160);
        set_skill("yangyanshu", 100);
        set_skill("yunv-xinfa", 150);    //��Ů�ķ�
        set_skill("sword", 150);
        set_skill("yunv-jian", 150);     //��Ů��
        set_skill("quanzhen-jian",130);  //ȫ�潣
        set_skill("dodge", 160);
        set_skill("yunv-shenfa", 160);   //��Ů��
        set_skill("parry", 150);
        set_skill("hubo", 120);          //˫�ֻ���
        set_skill("unarmed",150);
        set_skill("meinv-quan", 160);    //��Ůȭ��
        set_skill("literate",120);
        set_skill("qufeng",150);         //����֮��
        set_skill("wuzhan-mei",150);
        set_skill("strike",100);
        set_skill("tianluo-diwang",200);         //����֮��

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");

        create_family("��Ĺ��", 4, "����");


        set("book_count", 1);
        set("count",3);
        set("yfzhen",3);


        set("env/wimpy", 40);
        setup();

        carry_object("clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/baipao")->wear();

}

