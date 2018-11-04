// sample master.c code
// xiake island master.c
#include <ansi.h>
inherit NPC;
string* names = ({
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

string* ids = ({
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
//----���»�ӭ��ӣ�nm2��Ҫһ���Ŀ��֣��Ա����������--------------
string* nm2 = ({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"��","��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","�","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","ǿ","��","ɽ",
"̩","��","ͦ","ΰ","��","��","��","��",
"��","�","��","��","��","��",
});

#include <ansi.h>
void away();

void create()
{
   int i = random(sizeof(names));
  set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({ids[i]}));
        set("nickname", HIG"������ʿ"NOR);
//        set_name("������ʿ", ({ "xia shi","xia","shi" }));
        set("gender", "����");
        set("age", 22);
        set("long", 
                "����һ��Ӣ���������ˣ������������������ƺ���һ��СС���֡�\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 15);
        set("con", 20);
        set("dex", 25);
        set("bac", 15);

        set("qi", 300);
        set("max_qi", 300);
        set("jingli", 200);
        set("max_jingli", 200);
        set("neili", 100);
        set("max_neili", 100);
        
        set("combat_exp", 1000);
        
         set_skill("force", 100);
         set_skill("xuantian-wuji", 140);
         set_skill("dodge", 380 + random(30));
  
        set_skill("jinding-zhang", 340);
        set_skill("huifeng-jian", 280);
        set_skill("kunlun-shenfa", 240);
        set_skill("strike", 220 + random(30));
        set_skill("kunlun-zhang", 320 + random(30));
        set_skill("parry", 340);
        set_skill("sword", 340);
        set_skill("linji-zhuang", 280);
        set_skill("literate", 280);

        set_temp("apply/armor", 250);
        set_temp("apply/damage", 60);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.jue" :),
                (: perform_action, "sword.liaoyuan" :),
                 (: perform_action, "strike.bashi" :),
                (: perform_action, "strike.puzhao" :),                            
        }) );
        map_skill("dodge", "kunlun-shnfa");
        map_skill("strike", "kunlun-zhang");
  	prepare_skill("strike", "kunlun-zhang");
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        map_skill("dodge", "kunlun-shnfa");
   
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("sword","huifeng-jian");
        map_skill("parry","jinding-zhang");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 150);
 
        setup(); 
        carry_object("/clone/weapon/gangjian")->wield(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}

void away()
{
        if( living(this_object()) )
        {
                message_vision(this_object()->query("name") + "һ�����Ѿ��������������ʧ�ˡ�\n", this_object());
                destruct(this_object());
        }
        return;
}

void die()
{
        object ob, me, corpse;
int exp,pot;        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;        
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
if (me && me->query("tzjob"))
{
        message_vision(WHT"$N�ҽ�һ��,�������ְ���...���ض�����\n"NOR,ob,me);
        me->set("tzjob",0);
        me->add("score",50);
exp= random(280) + 180;
pot= random(280) + 150;
               me->add("combat_exp",exp);
               me->add("potential",pot);
   tell_object(me, "�㱻������"+chinese_number(exp)+"�㾭��ֵ��\n"+chinese_number(pot)+"��Ǳ��\n");

        me->add("shen",-100);
}
        destruct(this_object());
        destruct(ob);
        return;
}
void init()
{
        remove_call_out("leave");
        call_out("leave",120);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "���·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
