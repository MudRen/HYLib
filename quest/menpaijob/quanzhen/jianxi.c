#include <command.h>
#include <ansi.h>

inherit NPC;

int do_copy(object me,int maxpot);
int do_back(object me);

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

void create()
{
   int i = random(sizeof(names));
  set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({ids[i]}));
    set("gender", "����" );//�Ա��������Ӧ
   set("per",35);
        set("gender", "����");
         set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 14500);
        set("max_neili", 14500);
        set("jiali", 100);
        set("combat_exp", 2500000);
        set("score", 200000);

        set_skill("necromancy", 100);
        set_skill("force", 100);
        set_skill("longxiang", 100);
        set_skill("dodge", 100);
        set_skill("shenkong-xing", 200);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 200);
        set_skill("parry", 220);
        set_skill("cuff", 200);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 200);
        set_skill("lamaism", 200);
        set_skill("literate", 200);
        set_skill("hammer", 200);
        set_skill("riyue-lun", 200);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");
        map_skill("hammer", "riyue-lun");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 50);
	set("chat_chance_combat", 20);  
	set("chat_msg_combat", ({
                (: perform_action, "hammer.wushuai" :),
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
	}) );
              set("max_qi", 450); 
        set("eff_jingli", 400); 
        set("neili", 700); 
        set("max_neili", 700);
        set("jiali", 30);
        setup();
        carry_object("/d/xueshan/obj/jinlun")->wield();
        carry_object("/d/xueshan/obj/p-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
}

int do_copy(object me,int maxpot)
{
        int i,j;
        object ob;
        ob = this_object();
        i=me->query_skill("force",1);
//        i = i +10+ random(10);
//        if( i < 100) i = 100;
        


        ob->set("str", (me->query("str") * 4 / 5));
        ob->set("dex", (me->query("dex") * 4 / 5));
        ob->set("combat_exp", (me->query("combat_exp")));
        ob->set("combat_exp",me->query("combat_exp") * 4 / 5);
        ob->set("max_jing",me->query("max_jing")* 3 / 4);
        ob->set("eff_jing",me->query("max_jing")* 3 / 4);
        ob->set("jing",me->query("max_jing")* 3 / 4);
        ob->set("max_qi",me->query("max_qi")* 3 / 4);
        ob->set("eff_qi",me->query("max_qi")* 3 / 4);
        ob->set("qi",me->query("max_qi")* 3 / 4);
        ob->set("max_jingli",me->query("max_jingli")* 3 / 4);
        ob->set("eff_jingli",me->query("max_jingli")* 3 / 4);
        ob->set("jingli",me->query("max_jingli")* 3 / 4);
        ob->set("max_neili",me->query("max_neili")* 3 / 4);
        ob->set("neili",me->query("max_neili")* 3 / 4);
        if (me->query_skill("force",1)>5)
{
        ob->set_skill("force", me->query_skill("force",1));
        ob->set_skill("longxiang", me->query_skill("force",1)* 2 / 4);
        ob->set_skill("shenkong-xing", me->query_skill("force",1)* 2 / 4);
        ob->set_skill("yujiamu-quan", me->query_skill("force",1)* 2 / 4);
        ob->set_skill("riyue-lun",me->query_skill("force",1)* 2 / 4);
        ob->set_skill("dodge", me->query_skill("force",1)* 2 / 4); 
        ob->set_skill("sword", me->query_skill("force",1)* 2 / 4); 
        ob->set_skill("mingwang-jian", me->query_skill("force",1)* 2 / 4); 
        ob->set_skill("parry",me->query_skill("force",1)* 2 / 4); 
        ob->set_skill("hammer", me->query_skill("force",1)* 2 / 4);
        ob->set_skill("unarmed", me->query_skill("force",1)* 2 / 4); 
}
        if (me->query_skill("force",1)>5)
{
if (random(10)>8)
{
        ob->set_skill("force", me->query_skill("force",1));
        ob->set_skill("longxiang", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("shenkong-xing", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("yujiamu-quan", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("riyue-lun",me->query_skill("force",1)* 3 / 4);
        ob->set_skill("dodge", me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("sword", me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("mingwang-jian", me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("parry",me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("hammer", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("unarmed", me->query_skill("force",1)* 3 / 4); 
}
}   
if (me->query("combat_exp") >6000000
||(int)me->query_skill("jiuyin-zhengong",1)>480)
{
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "hammer.wushuai" :),
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
        }) );
}
//        set_skill("linji-zhuang",i*3/4);
	ob->set("max_qi", 3000+i*30); 
        ob->set("jing", me->query("eff_jing")+5000); 
        ob->set("eff_jing", me->query("eff_jing")+5000); 
        ob->set("eff_jingli", me->query("eff_jingli")+5000);         
        ob->set("eff_jing", me->query("eff_jing")); 
        ob->set("max_neili", 2000+i*15); 
        ob->set("jiali", i/6);
        ob->reincarnate(); 
        ob->set("qi",ob->query("max_qi"));
        ob->set("neili",ob->query("max_neili"));
		call_out("do_back", 200,  ob);  
        return 1;
}

int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"�Ҵ�ææ���뿪�ˡ�\n", ({me}));	
  destruct(me); 
  return 1;
}


void die()
{
   int kar, exp, pot;

        object me = this_object()->query_temp("last_damage_from");
        object corpse,zhi;      
   kar = random(me->query("kar")) * 15;
   if (kar > 450) kar = 450;
   exp = 1200 + kar;
   pot = 600 + random(exp);
if (me)
{
        if (me->query("qzjob") == 1 && this_object()->query_temp("host")==me->query("id")){
        message_vision(HIY"�����ڳɹ��ı�����ȫ���,����书��Ϊ���˺ܴ�ĳ���.\n"NOR, me);
                  message_vision(HIC "\n����$N�ɹ����������ɹŲ��ӣ���������\n"
                + chinese_number(exp / 2) + "��ʵս���飬\n"
                + chinese_number(pot / 2) + "��Ǳ�ܣ�\n"
                + chinese_number(50) + "��������Ϊ��л��\n" NOR, me);
                me->add("combat_exp", exp / 2);
                me->add("potential", pot / 2);
                me->add("score",50);
                me->delete("qzjob");
me->apply_condition("quanzhenjob",0);
                }

        corpse = new("/clone/misc/corpse");
        corpse->set("name",HIW "�ɹ�ǿ����ʬ��" NOR);
        corpse->set("long","����ѩɽ�µĻ��̵���,��һ���Ϻ����ģ�ͷ��ɮñ����\nȻ�������Ѿ����ˣ�ʣ��һ�߳�ª��ʬ�塣\n");
        corpse->move(environment(this_object()));
        corpse->set_max_encumbrance(1000);        
        me->add("MKS", 1);
}
        destruct(this_object());
}
