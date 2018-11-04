#include <ansi.h>
int do_walk();
inherit NPC;
string  ask_job();
string *first_name = ({ "��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��", }); 
string *name_words = ({ "һ","��","��","��","��","��","��","��","��","ʮ", });
string *color_title = ({"[��ɱ��]ɱ��","[��ɷ��]ɱ��",});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *data=({
(["name":"�ٱ�",	"id":"guan bing",	"mw":-1,"weapon":"gangdao",]),
(["name":"���",	"id":"yu fu",	"mw":-1,]),
(["name":"�к�",	"id":"boy",	"mw":-1,]),
(["name":"Ů��",	"id":"girl",	"mw":1,]),
(["name":"��С��",	"id":"xiao er",	"mw":-1,]),
(["name":"Ա��",	"id":"yuanwai",	"mw":-1,]),
(["name":"���",	"id":"ge ji",	"mw":1,]),					
(["name":"�ܼ�",	"id":"guan jia",	"mw":-1,]),
(["name":"�깫",	"id":"gui gong",	"mw":-1,]),
(["name":"����",	"id":"hong niang",	"mw":1,]),
(["name":"С���",	"id":"xiao hunhun",	"mw":-1,]),
(["name":"��ɮ",	"id":"huogong seng",	"mw":-1,]),
(["name":"���",	"id":"huoji",	"mw":-1,]),
(["name":"����ɮ",	"id":"kanmen seng",	"mw":-1,]),
(["name":"����Ů��",	"id":"girl",	"mw":1,]),
(["name":"̤����Ů",	"id":"girl",	"mw":1,]),
(["name":"����Ů��",	"id":"girl",	"mw":1,]),
(["name":"СѾͷ",	"id":"littlegirl",	"mw":1,]),											
(["name":"��ͯ",	"id":"ma tong",	"mw":-1,]),
(["name":"������ͷ",	"id":"lao tou",	"mw":-1,]),		
(["name":"������",	"id":"lao popo",	"mw":1,]),		
(["name":"ǩ��",	"id":"qian ke",	"mw":-1,]),		
(["name":"����С��",	"id":"tang fan",	"mw":-1,]),				
(["name":"�ò�",	"id":"ya chai",	"mw":-1,]),		
(["name":"ɽ��",	"id":"shan zei",	"mw":-1,]),		
(["name":"��ʦ",	"id":"chu shi",	"mw":-1,]),		
(["name":"�����",	"id":"fu ren",	"mw":1,]),		
(["name":"Ů���",	"id":"guan jia",	"mw":1,]),				
(["name":"����",	"id":"lama",	"mw":-1,]),		
(["name":"������",	"id":"lama",	"mw":-1,]),		
(["name":"����",	"id":"pu yi",	"mw":-1,]),		
(["name":"��ǰ����",	"id":"shi wei",	"mw":-1,	"weapon":"gangdao",]),		
(["name":"����Ӫ����",	"id":"shi wei",	"mw":-1,	"weapon":"gangdao",]),				
(["name":"����",	"id":"tiejiang",	"mw":-1,]),		
(["name":"��ؤ",	"id":"qi gai",	"mw":-1,]),			
(["name":"Ů��ؤ",	"id":"nvqi gai",	"mw":1,]),			
(["name":"��ʿ",	"id":"dao shi",	"mw":-1,]),			
(["name":"Ů��ʿ",	"id":"nv daoshi",	"mw":1,]),
(["name":"Ϸ��",	"id":"xi zi",	"mw":1,]),		
(["name":"Ѿ��",	"id":"ya huan",	"mw":1,]),	
(["name":"԰��",	"id":"yuan ding",	"mw":-1,]),	
(["name":"�ƹ�",	"id":"zhanggui",	"mw":-1,]),	
(["name":"�ɲ�Ů",	"id":"cha girl",	"mw":-1,]),	
(["name":"����ʦ",	"id":"old chanshi",	"mw":-1,]),	
(["name":"����",	"id":"dao ke",	"mw":-1,]),	
(["name":"�����",	"id":"jinxiang ke",	"mw":-1,]),	
(["name":"�컨����",	"id":"hong hua",	"mw":-1,]),	
(["name":"����",	"id":"jian ke",	"mw":-1,]),	
(["name":"���",	"id":"ma fu",	"mw":-1,]),	
(["name":"ý��",	"id":"mei po",	"mw":-1,]),		
(["name":"������",	"id":"mengmianren",	"mw":-1,]),			
(["name":"�",	"id":"poor man",	"mw":-1,]),				
(["name":"����",	"id":"shu sheng",	"mw":-1,]),				
(["name":"�Ϻ���",	"id":"lao heshang",	"mw":-1,]),				
(["name":"Сɳ��",	"id":"xiao shami",	"mw":-1,]),				
(["name":"����",	"id":"tiao fu",	"mw":-1,]),							
(["name":"�ο�",	"id":"youke",	"mw":-1,]),				
(["name":"���Ӹ�",	"id":"gongzi",	"mw":-1,]),				
(["name":"�Ů",	"id":"bi nu",	"mw":1,]),				
(["name":"���",	"id":"ni gu",	"mw":1,]),							
(["name":"С��",	"id":"xiao fan",	"mw":-1,]),			
(["name":"��Ů",	"id":"ji nv",	"mw":1,]),	
(["name":"�ϸ���",	"id":"fu zi",	"mw":1,]),	
(["name":"��ͷ",	"id":"bu tou",	"mw":-1,	]),
(["name":"�첶",	"id":"kuai bu",	"mw":-1,	]),
(["name":"����",	"id":"tie bu",	"mw":-1,	]),
(["name":"����",	"id":"ya yi",	"mw":-1,	]),
(["name":"����",	"id":"gong gong",	"mw":-1,	]),
(["name":"����",	"id":"pao tang",	"mw":-1,	]),
(["name":"�ŷ�",	"id":"jiao fu",	"mw":-1,	]),
(["name":"�÷�",	"id":"cai feng",	"mw":-1,	]),
(["name":"ҩʦ",	"id":"yao shi",	"mw":-1,	]),
(["name":"�ٲ�",	"id":"guan cha",	"mw":-1,	]),
(["name":"�佫",	"id":"wu jiang",	"mw":-1,	]),
(["name":"ɽ��ͷ",	"id":"shan zeitou",	"mw":-1,	]),
(["name":"�͵���",	"id":"huo ji",	"mw":-1,	"weapon":"gangdao",	]),
(["name":"����",	"id":"shi wei",	"mw":-1,	"weapon":"changqiang",	]),
(["name":"����",	"id":"tie jiang",	"mw":-1,	"weapon":"gangdao",	]),
(["name":"��åͷ",	"id":"liumang tou",	"mw":-1,	"weapon":"gangjian",	]),
(["name":"����",	"id":"gui gongzi",		"mw":-1,	"weapon":"gangjian",	]),
(["name":"����",	"id":"xing ze",	"mw":-1,	"weapon":"gangdao",]),
(["name":"����ͷ",	"id":"tufei tou",	"mw":-1,	"weapon":"changbian",	]),
(["name":"Ϸ��",		"id":"xi zi",	"mw":-1,	"weapon":"lianzi",]),
(["name":"̨���̷�",	"id":"shang fan",		"mw":-1,	"weapon":"hammer",	]),
(["name":"��������",	"id":"yi ren",	"mw":-1,	"weapon":"gangjian",]),
(["name":"������",	"id":"kanzu ren",	"mw":-1,	"weapon":"changbian",	]),
(["name":"����",		"id":"lie ren",	"mw":-1,	"weapon":"lianzi",]),
(["name":"̨������",	"id":"old lieren",		"mw":-1,	"weapon":"hammer",	]),
(["name":"������",	"id":"muyang ren",	"mw":-1,	"weapon":"gangjian",]),
(["name":"ũ��",	"id":"nong fu",	"mw":-1,	"weapon":"gangjian",]),
(["name":"Ƥ����",	"id":"pihuo sang",	"mw":-1,	"weapon":"changbian",	]),
(["name":"ʯ��",		"id":"shi jiang",	"mw":-1,	"weapon":"lianzi",]),
(["name":"����",	"id":"dao ren",		"mw":-1,	"weapon":"hammer",	]),
(["name":"�ο�",	"id":"you ke",	"mw":-1,	"weapon":"gangjian",]),
(["name":"��ͯ",	"id":"shu tong",	"mw":1,	"weapon":"gangjian",]),
(["name":"��Ӫ����",	"id":"guan bing",	"mw":-1,	"weapon":"changbian",	]),
(["name":"Ա��",		"id":"yuan wai",	"mw":-1,	"weapon":"lianzi",]),
(["name":"����",	"id":"bi qiu",		"mw":-1,	"weapon":"hammer",	]),
(["name":"��å",	"id":"liu mang",	"mw":-1,	"weapon":"gangjian",]),
});

#include "action2.h"
#include "party2.h"
mapping *menpai=({
(["mp":"wudang",]),
(["mp":"lingjiu",]),
(["mp":"taohua",]),
(["mp":"tiandihui",]),
(["mp":"mingjiao",]),
(["mp":"gumu",]),
(["mp":"huashan",]),
(["mp":"gaibang",]),
(["mp":"quanzhen",]),
(["mp":"dali",]),
(["mp":"tiezhang",]),
(["mp":"murong",]),
(["mp":"kunlun",]),
(["mp":"lingxiao",]),
(["mp":"wdjiao",]),
(["mp":"baituo",]),
(["mp":"emei",]),
(["mp":"xiaoyao",]),		
(["mp":"mizong",]),
(["mp":"xingxiu",]),
(["mp":"feitian",]),
(["mp":"shenlong",]),
(["mp":"tangmen",]),		
(["mp":"riyue",]),
(["mp":"mizong1",]),
(["mp":"shaolin",]),
(["mp":"riyue1",]),
(["mp":"jiuyin",]),
(["mp":"noname",])
});
string *ns = ({	"force",
		"dodge",
		"parry",
		"unarmed",
		"strike",
		"cuff",
		"finger",
		"claw",
		"hand",
		"leg",
		"sword",
		"blade",
		"whip",
		"hammer",
		"staff",
		"axe",
		"literate",
		"shenzhao-jing",
});
string *cmds = ({"wield", "unwield", "wear", "remove", "enable", "jifa", "prepare", "bei", "exert",
"yun", "perform", "yong", "enforce", "jiali"});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *data=({
(["id":"zuizui","title":"ؤ��Ŵ�����","name":"׺׺ ",]),
(["id":"zhword","title":"������������","name":"���� ",]),
(["id":"danyingzi","title":"����BUG","name":"������ ",]),
(["id":"fox","title":"������","name":"���� ",]),
(["id":"cash","title":"���������һ","name":"��Ʊ ",]),
(["id":"fen","title":"����ڰ���ʹ","name":"���� ",]),
(["id":"lting","title":"�����滨���滨����","name":"�L���滨","sex":1,]),
(["id":"shazi","title":"��������ϴ�","name":"��� ",]),
(["id":"hotwing","title":"�������������佫","name":"������ʹ ",]),
(["id":"lavender","title":"�������","name":"޹�²�","sex":1,]),
(["id":"bakangel","title":"���ŵ��ߴ�����","name":"����ʹ","sex":1,]),
(["id":"rains","title":"��ɽ�ɵ�ʮ��������","name":"СС��ʿ ",]),
(["id":"guipu","title":"������å����˭������","name":"���� ",]),
(["id":"flyt","title":"���۸����Ϲ���","name":"����","sex":1,]),
(["id":"qing","title":"���ϵ�һŮ��","name":"����Ũ","sex":1,]),
(["id":"sos","title":"������ͳ","name":"�ɷɷɷɻ� ",]),
(["id":"dings","title":"ֻ����������","name":"Ѽ�� ",]),
(["id":"damenly","title":"�Ҿ������ɱ�ɻ���һë����","name":"ȱ�¾�ʿ ",]),
(["id":"Qlbl","title":"�嶾�̳���","name":"��竹��� ",]),
(["id":"xbd","title":"�����һ","name":"С���� ",]),
(["id":"game","title":"Ī˼�����������Ҿ���ǰ���ޱ�","name":"��Ϸ ",]),
(["id":"amei","title":"�嶾�̳���","name":"ǧɽĺѩ","sex":1,]),
(["id":"zbabla","title":"�Ұ��汦��","name":"��ң���� ",]),
(["id":"lunar","title":"�һ����ڶ�������","name":"ѩ÷","sex":1,]),
(["id":"yoyo","title":"�һ����ڶ�������","name":"���� ",]),
(["id":"snowfly","title":"��Ҫ������һ��","name":"ѩ��Ʈ","sex":1,]),
(["id":"wto","title":"���ư��ʮ�������","name":"������ŷ ",]),
(["id":"hadis","title":"���ư��ʮ�������","name":"����˹ ",]),
(["id":"angel","title":"������������������ʮ�ߴ�������","name":"糴嵶�� ",]),
(["id":"zohu","title":"��˵���汻�״�����","name":"���� ",]),
(["id":"dfei","title":"��ң�ɻ���ʹ��","name":"��� ",]),
(["id":"bakangel","title":"���ŵ��ߴ�����","name":"����ʹ","sex":1,]),
(["id":"woodtian","title":"�ҵ�˧������ʮ����͵�����","name":"�Ұ�����Ů ",]),
(["id":"kjhojin","title":"���ŵ��ߴ�����","name":"ˮ���","sex":1,]),
(["id":"thill","title":"�����ڲ�����������","name":"������ ",]),
(["id":"dido","title":"��Ӱ���ťҥ���","name":"������ ",]),
(["id":"cold","title":"�����﷢��һ����","name":"���� ",]),
(["id":"scan","title":"����ͷ�ŵ���","name":"��Ӣ���� ",]),
(["id":"lubinh","title":"һ����ǰ��û���㣬Ҳû����","name":"С���� ",]),
(["id":"lightning","title":"�����ɵ���ʮ�������","name":"���� ",]),
(["id":"xiaomei","title":"�䵱�ɵڶ�������","name":"С��","sex":1,]),
(["id":"dldi","title":"�������������佫","name":"�����幤 ",]),
(["id":"mafan","title":"��ң�ɻ���ʹ��","name":"�鷳 ",]),
(["id":"hailoo","title":"ȫ��̵ڶ�������","name":"��������","sex":1,]),
(["id":"bingxueer","title":"�����Ľ��е���","name":"��ѩ��","sex":1,]),
(["id":"caree","title":"�����ŵ���������","name":"��������","sex":1,]),
(["id":"damenl","title":"����ͷ","name":"��Ǯ�뷢�� ",]),
(["id":"xiaotian","title":"ͨ������±�Х��͵�������","name":"Х�� ",]),
(["id":"waaas","title":"������һ������","name":"�ض�","sex":1,]),
(["id":"dbabla","title":"�嶾����","name":"��а ",]),
(["id":"lyf","title":"������·�㲻��ѽ","name":"������","sex":1,]),
(["id":"loveyqh","title":"��ɽ�ɵ�ʮ�Ĵ�����","name":"ˮ�� ",]),
(["id":"lovefox","title":"���ϸ�","name":"����","sex":1,]),
(["id":"linda","title":"���ã������Լ���ͦ����...","name":"�׾���","sex":1,]),
(["id":"lindy","title":"��֮��","name":"Ľ����","sex":1,]),
(["id":"lexy","title":"��ɽ�ɵ�ʮ�Ĵ�����","name":"����ң ",]),
(["id":"laiyinhate","title":"��Ӱ�����ų�","name":"������� ",]),
(["id":"yzx","title":"��һ���ķ���","name":"�������� ",]),
(["id":"xnh","title":"ѩɽ�����Ŵ����","name":"���� ",]),
(["id":"xjhjin","title":"��ң�ɵ���","name":"����","sex":1,]),
(["id":"xiaoxuan","title":"��ġ�sk�������ˣ�","name":"������ ",]),
(["id":"xdb","title":"��ɽ����","name":"ѩ���� ",]),
(["id":"wumi","title":"Ư���Ļ�����","name":"���� ",]),
(["id":"wukong","title":"����Ľ��","name":"�����ʥ ",]),
(["id":"wishluck","title":"�л�ʥ���⽻����","name":"С����","sex":1,]),
(["id":"winco","title":"������������֪�����������һ�","name":"�Ʒ� ",]),
(["id":"wanxia","title":"������±��޼۽�ˮԶɽ������","name":"��ϼ","sex":1,]),
(["id":"wanghu","title":"���м��˹�����һ�轣�����ķ�","name":"������� ",]),
(["id":"waaa","title":"��������Ϊ����","name":"���� ",]),
(["id":"myth","title":"����Ľ�ݵڶ�������","name":"Ľ�ݲ� ",]),
(["id":"vov","title":"õ����ʹ^_^","name":"���� ",]),
(["id":"tyywl","title":"����ɽ�ɵڶ�������","name":"��ҰԴ���� ",]),
(["id":"ttss","title":"�����޵��Ʋ���","name":"������","sex":1,]),
(["id":"tianjun","title":"���ϸ�ɽ������Ϫ��","name":"���� ",]),
(["id":"tcl","title":"ѩɽ���׼ҵ���","name":"���� ",]),
(["id":"taotao","title":"����ɽ�ɵڶ�������","name":"OhMyGod ",]),
(["id":"sug","title":"��ȹ����˭��Ů","name":"�����","sex":1,]),
(["id":"sprite","title":"��Ĺ�ɵ��Ĵ�����","name":"С���� ",]),
(["id":"sony","title":"�䵱�ɵڶ�������","name":"Ե�� ",]),
(["id":"snq","title":"�����ǳ���","name":"СС ",]),
(["id":"snow","title":"����Ϊ��","name":"������ѩ","sex":1,]),
(["id":"smj","title":"Ҫ exp","name":"������ ",]),
(["id":"smile","title":"������","name":"���� ",]),
(["id":"sjmoxj","title":"���","name":"����ʫ�� ",]),
(["id":"siren","title":"�������","name":"��� ",]),
(["id":"shuanger","title":"����С��Ů","name":"����˪","sex":1,]),
(["id":"shanc","title":"���չ��ڶ�������","name":"����","sex":1,]),
(["id":"sgy","title":"����","name":"С�� ",]),
(["id":"scare","title":"�Ұ� �³�","name":"Ц���� ",]),
(["id":"rui","title":"Amy�ľ��� ������","name":"��ѩƮ��","sex":1,]),
(["id":"quanjia","title":"������ˮ","name":"Ȫ��","sex":1,]),
(["id":"qkry","title":"��������ν����״�����","name":"Ǭ������ ",]),
(["id":"qiuqiu","title":"ؤ���ʮ�Ŵ�����","name":"���� ",]),
(["id":"qazqaz","title":"��������е���","name":"������ ",]),
(["id":"pxf","title":"~_______~","name":"ľ�� ",]),
(["id":"pcgame","title":"��ң�ɻ���ʹ��","name":"���� ",]),
(["id":"papaya","title":"�����԰����� ","name":"���� ",]),
(["id":"orange","title":"��ʦ��","name":"����","sex":1,]),
(["id":"ooo","title":"����HY��å�ϴ�","name":"���֮�� ",]),
(["id":"only","title":"����Թ�","name":"�����о� ",]),
(["id":"nvnv","title":"��һ��·ä","name":"���� ",]),
(["id":"npc","title":"ȫ��̵ڶ�������","name":"С����","sex":1,]),
(["id":"name","title":"��Ʒ����","name":"ֱ���� ",]),
(["id":"mzlm","title":"�������ֺ�","name":"���� ",]),
(["id":"marine","title":"��Ӱ���š����","name":"����Ź� ",]),
(["id":"means","title":"���ư��Ϲٰ�������","name":"��˼ ",]),
(["id":"miean","title":"���ε���û��Ϊ�����ؿ���Ǯ","name":"���� ",]),
(["id":"mingyang","title":"�һ��콣","name":"���� ",]),
(["id":"mini","title":"����μҵ�ʮ�ߴ�����","name":"���� ",]),
(["id":"mmm","title":"���������벻Ҫ��me˵��","name":"�Ž�һ�� ",]),
(["id":"mrf","title":"����Ľ�ݵ���������","name":"Ľ�ݷ� ",]),
(["id":"mryh","title":"���","name":"�ƻ� ",]),
(["id":"myboy","title":"���ա��ˡ隸��Ǯ","name":"������� ",]),
(["id":"mygirl","title":"С�¹���","name":"����","sex":1,]),
(["id":"lang","title":"�ԾƵ��裬��������","name":"�˷��� ",]),
(["id":"langer","title":"����������������","name":"���� ",]),
(["id":"legs","title":"ѡ������ ������ѡ","name":"��������","sex":1,]),
(["id":"lbxx","title":"ѩɽ���׼ҵ���","name":"����С�� ",]),
(["id":"lengxin","title":"��������ʦ","name":"���� ",]),
(["id":"ling","title":"ȫ��̵ڶ�������","name":"���","sex":1,]),
(["id":"ljgbook","title":" �������ʵ���������Ϊʲô������","name":"����","sex":1,]),
(["id":"lkdd","title":"������������������������ޱ�","name":"�ٱ��Ǿ� ",]),
(["id":"kara","title":"�����¸ɱ�","name":"����","sex":1,]),
(["id":"keeny","title":"����������Ҫ��������Ҳ������","name":"���� ",]),
(["id":"keyboard","title":"������ˡ���С�","name":"���� ",]),
(["id":"kgb","title":"��Զ��(ͨ����)","name":"����С�� ",]),
(["id":"killman","title":"�ɻ�С��","name":"�����Ǯ�� ",]),
(["id":"jad","title":"������ȸ¥֮�󵱼�","name":"���� ",]),
(["id":"jianxin","title":"��̫�ĵ���","name":"��̫ ",]),
(["id":"jxy","title":"��ɽ�ɵ�ʮ��������","name":"Ф�� ",]),
(["id":"icefox","title":"�þ�û����","name":"���� ",]),
(["id":"hadis","title":"���ư��ʮ�������","name":"����˹ ",]),
(["id":"hechuan","title":"ؤ��Ŵ�����","name":"��Ӣ�� ",]),
(["id":"hehaia","title":"����ʹ��","name":"�κ��� ",]),
(["id":"himura","title":"����μҵ�ʮ�ߴ�����","name":"���� ",]),
(["id":"honda","title":"��ӭ����www.fivekids.com","name":"���� ",]),
(["id":"huakai","title":"�����ǵ��ߴ�����","name":"���仨�� ",]),
(["id":"hylijun","title":"��ɽ�ɵ�ʮ��������","name":"����è ",]),
(["id":"hxt","title":"ʥ�����վ","name":"��ֽһ�� ",]),
(["id":"huihui","title":"�����ɵ���ʮ������","name":"��Ľ ",]),
(["id":"gameking","title":"�����ɾ����ڶ�������","name":"��Ϸ֮�� ",]),
(["id":"gaoc","title":"�߲��Թ�����","name":"�߲� ",]),
(["id":"gmxy","title":"����","name":"���� ",]),
(["id":"grape","title":"�մ�һ��¹����","name":"�̶��� ",]),
(["id":"green","title":"�����Թſ����","name":"��Ҷ�� ",]),
(["id":"fadai","title":"һ���˵�׷��","name":"���� ",]),
(["id":"fall","title":"�մ�һ��¹����","name":"������","sex":1,]),
(["id":"fff","title":"�����ĺ���","name":"���� ",]),
(["id":"ffs","title":"����","name":"��а ",]),
(["id":"fgy","title":"���ǽ�","name":"������ ",]),
(["id":"flower","title":"��������������ū","name":"������","sex":1,]),
(["id":"foryou","title":"Ϊ������","name":"��ʫ","sex":1,]),
(["id":"foxzzz","title":"�մ�һ��¹����","name":"ѩ��","sex":1,]),
(["id":"frfr","title":"ؤ��Ŵ�����","name":"���� ",]),
(["id":"ftoiloveyou","title":"wait me xue yitiantulong","name":"ѩ����ʥ ",]),
(["id":"fury","title":"һ�������������ҵ���ͷ��","name":"��ƽ�� ",]),
(["id":"fusheng","title":"����ɳ����ǧ����һЦ������","name":"��.���� ",]),
(["id":"eddie","title":"Amy�Ĵ��׾��������ų�","name":"������","sex":1,]),
(["id":"ehuan","title":"���� no look","name":"����","sex":1,]),
(["id":"enjoy","title":"ɫ��","name":"���� ",]),
(["id":"eric","title":"��ң�ɵ��Ĵ�����","name":"���� ",]),
(["id":"dairun","title":"�մ�һ��¹����","name":"���� ",]),
(["id":"dali","title":"�ܲ������","name":"���� ",]),
(["id":"datank","title":"�����ɵ���������","name":"��̹�� ",]),
(["id":"dhxy","title":"���ϴ����򡿱��Ϲ�Ѳ��ɱ��","name":"������ ",]),
(["id":"digu","title":"���ڹ��Ϻ����ӣ����Ͽ����","name":"ͯ��ϱ ",]),
(["id":"dldi","title":"�������������佫","name":"�����幤 ",]),
(["id":"dodo","title":"�»�Ұ��","name":"ûƷ���� ",]),
(["id":"donkey","title":"���ŵ��ߴ�����","name":"¿�� ",]),
(["id":"duly","title":"�ɻ�С��","name":"���� ",]),
(["id":"caiyi","title":"��ң�ɻ���ʹ��","name":"����","sex":1,]),
(["id":"camin","title":"�ɻ�С��","name":"Ц�� ",]),
(["id":"chaosheng","title":"Diablo12 www.love214.com","name":"���� ",]),
(["id":"cloud","title":"��ɽ�ɵ�ʮ��������","name":"���� ",]),
(["id":"com","title":"ǧ��˼��Ī����","name":"��� ",]),
(["id":"cutlove","title":"����ɽ�ɵڶ�������","name":"�ᵶ ",]),
(["id":"baggio","title":"����Ǳ��","name":"��ԯ�� ",]),
(["id":"baishi","title":"mely��רְ����","name":"������","sex":1,]),
(["id":"banana","title":"�����ɵ���������","name":"�㽶 ",]),
(["id":"baoer","title":"��ɽ�ɵ�ʮ��������","name":"�ֱ��� ",]),
(["id":"battlee","title":"����Ż���������ʦ��","name":"Ѧ��","sex":1,]),
(["id":"bear","title":"�ҹһ�������","name":"Ц�� ",]),
(["id":"bee","title":"��Ϸ����","name":"Ů����","sex":1,]),
(["id":"bihu","title":"С����","name":"�ڻ� ",]),
(["id":"biluo","title":"��ة��","name":"����������","sex":1,]),
(["id":"bird","title":"����ʹ��","name":"����","sex":1,]),
(["id":"bingxueer","title":"�����Ľ��е���","name":"��ѩ��","sex":1,]),
(["id":"bmr","title":"����","name":"ѩ��","sex":1,]),
(["id":"budai","title":"����Ľ�ݵ��Ĵ�����","name":"������ȥ ",]),
(["id":"bullet","title":"��Ҫ! ��Ҫ�� ��������","name":"С�� ",]),
(["id":"admire","title":"����������Ѱ����","name":"���� ",]),
(["id":"aka","title":"��������","name":"���� ",]),
(["id":"akan","title":"С����","name":"Ī������ ",]),
(["id":"amejio","title":"�һ����ڶ�������","name":"���","sex":1,]),
(["id":"amy","title":"�������µ�һ","name":"����","sex":1,]),
(["id":"ant","title":"��˭�ڶ���˵����������","name":"����","sex":1,]),
(["id":"anran","title":"��Ĺ֮����է��","name":"������Ȼ ",]),
(["id":"aoe","title":"�������� ���سɷ�","name":"�ɰ� ",]),
(["id":"axax","title":"Ը�������̳�� ��������ɨ�仨","name":"����",])
});

mixed get_auto_actions(string action);
void change_combat_mode(object me, int mode);
int ask_job();
int ask_job2();
void create()
{
	mapping npc,mp,j;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int i,k,a,b,c,d,e,f,temp;
	npc=data[random(sizeof(data))];
	mp=menpai[random(sizeof(menpai))];
	j=ps[random(sizeof(ps))];
ob=this_object();
	k=random(29);
	//k=11;
	sex=npc["sex"];
	set_name(npc["name"]+NOR,({ npc["id"] }));
	set("title",(order[random(13)])+(npc["title"])+NOR);
set("nick","����Ա");
set("vendetta/authority",1);
	set("age",20+random(30));
        set("per",20+random(30));
if (sex)
set("gender", "Ů��" );
else set("gender", "����" );
	set("combat_exp",2000000+random(28000000));
set("skill_public",1);
set("pubmaster",1);
	set_temp("apply/attack",50);
	set_temp("apply/defense",200);
	set_temp("apply/armor",650);
	set_temp("apply/damage",650);
	set("max_force",2000);
	set_skill("unarmed",200);
	set_skill("sword",200);
	set_skill("club",200);
	set_skill("whip",200);
	set_skill("throwing",200);
	set_skill("parry",200);
	set_skill("dodge",200);
        set("tasknpc",1);
        set("dex",200);
        set("no_get",1);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
b=2000+random(8000);
a=8000+random(18000);
d=20+random(60);
set("str",d);
set("dex",100);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("jing",b);
        set("max_jing",b);
set("eff_jing",b);

        set("qi",a);
        set("max_qi",a);
set("eff_qi",a);
        set("neili",a);
        set("max_neili",a);
        i=220+random(800);
        e=220+random(800);
if (random(16)==0)
{
set("nickname",HIY"�书�߳�"NOR);
        set_skill("spells",650+random(300));
        set_skill("force",550+random(300));
	set_skill("unarmed",650+random(300));
	set_skill("sword",650+random(300));
	set_skill("club",650+random(300));
	set_skill("whip",650+random(300));
	set_skill("throwing",650+random(300));
	set_skill("parry",650+random(300));
        i=580+random(500);
        e=580+random(500);

}
else
if (random(16)==0)
{
set("nickname",HIY"�书����"NOR);
        set_skill("spells",850+random(300));
        set_skill("force",550+random(300));
	set_skill("unarmed",850+random(300));
	set_skill("sword",850+random(300));
	set_skill("club",850+random(300));
	set_skill("whip",850+random(300));
	set_skill("throwing",850+random(300));
	set_skill("parry",850+random(300));
        i=600+random(500);
        e=600+random(500);

}
else
if (random(16)==0)
{
set("nickname",HIB"����ḻ"NOR);
set("combat_exp",30000000+random(4800000));
       i=380+random(500);
        e=380+random(500);
}
else
if (random(16)==0)
{
set("nickname",HIR"ǿ����"NOR);
set("dex",300);
        set("jing",100000);
        set("max_jing",100000);
        set("eff_jing",100000);
        set("qi",100000);
        set("max_qi",100000);
        set("eff_qi",100000);
        set("neili",200000);
        set("max_neili",200000);
	set("combat_exp",8000000);
}
else
if (random(16)==0)
{
set("nickname",HIC"������ǿ"NOR);
d=188+random(88);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
else
if (random(20)==0)
{
        i=600+random(500);
        e=600+random(500);

set("dex",300);
        set("jing",100000);
        set("max_jing",100000);
        set("eff_jing",100000);
        set("qi",100000);
        set("max_qi",100000);
        set("eff_qi",100000);
        set("neili",100000);
        set("max_neili",100000);
      set_skill("magic-unarmed", 650+random(300));
      set_skill("magic-sword", 650+random(300));
      set_skill("magic-ice", 650+random(200));
      set_skill("magic-water", 650+random(200));
      set_skill("magic-fire", 650+random(200));
      set_skill("magic-earth", 650+random(200));
      set_skill("magic-light", 650+random(200));
      set_skill("magic-dark", 650+random(200));
        set_skill("spells",650+random(300));
        set_skill("force",550+random(300));
	set_skill("unarmed",650+random(300));
	set_skill("sword",650+random(300));
	set_skill("club",650+random(300));
	set_skill("whip",650+random(300));
	set_skill("throwing",650+random(300));
	set_skill("parry",650+random(300));
set("nickname",HIC"�����޵�"NOR);
        i=590+random(500);
        e=590+random(500);
d=88+random(88);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}

	this_object()->set("party",ps[k]["party"]);
	this_object()->set_skills(ps[k]["skills"]);
	this_object()->set_skill_map(ps[k]["skill_map"]);
	this_object()->set_skill_prepare(ps[k]["skill_prepare"]);

	for (k = 0; k < sizeof(ns); k++)
		this_object()->set_skill(ns[k], i);

		this_object()->set_skill("literate",i);
        this_object()->set_skill("shenzhao-jing",e);
if (mapp(skill_status = this_object()->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = this_object()->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
this_object()->set_skill(sname[i],e);//ɾ���Լ����й���
}
        this_object()->change_combat_mode();
set_skill("force", e);
set("chat_chance_combat", 80);
set("chat_msg_combat", get_auto_actions("perform"));
change_combat_mode(ob, 1);
        
f=1+random(8);        
	setup();
	        set("check_time", time());

	if (ob->query("gender")=="Ů��")
	{
	carry_object("/clone/cloth/female"+f+"-cloth")->wear();
	carry_object("/clone/cloth/female-shoe")->wear();
	}
else {
	carry_object("/clone/cloth/male"+f+"-cloth")->wear();
	carry_object("/clone/cloth/male-shoe")->wear();
}        
        set("chat_chance", 50);
        set("chat_msg", ({
                (: do_walk :),
                (: random_move :),
        }) );

        set("inquiry", ([
   	    "����"  : (: ask_job :),
	    "task"  : (: ask_job :),
            ]));
        if (stringp(ob->query_skill_mapped("sword"))) 
	carry_object(__DIR__"weapon/sword")->wield();
	if (stringp(ob->query_skill_mapped("blade"))) 
	carry_object(__DIR__"weapon/dao")->wield();
	if (stringp(ob->query_skill_mapped("whip"))) 
	carry_object(__DIR__"weapon/bian")->wield();
	if (stringp(ob->query_skill_mapped("hammer"))) 
	carry_object(__DIR__"weapon/hammer")->wield();
	if (stringp(ob->query_skill_mapped("staff"))) 
	carry_object(__DIR__"weapon/ban")->wield();
	if (stringp(ob->query_skill_mapped("axe"))) 
	carry_object(__DIR__"weapon/axe")->wield();
	if (stringp(ob->query_skill_mapped("throwing"))) 
	carry_object(__DIR__"weapon/throwing")->wield();

	add_money("silver",50+random(50));
}
       

mixed get_auto_actions(string action)
{
	int i, flag = 0;

	for (i = 0; i < sizeof(pfm); i++)
		if (pfm[i]["party"] == query("party")) {
			flag = 1;
			break;
		}
	if (!flag)
		return ({ });
	if (arrayp(pfm[i][action]))
		return pfm[i][action];
	else
		return ({ });
}

void change_combat_mode(object me, int mode)
{
	switch (mode) {
	case 0:
		delete("chat_chance_combat");
		delete("chat_msg_combat");
		set("jiali", 1);
		break;
	case 1:
		set("chat_chance_combat", 80);
		set("chat_msg_combat", get_auto_actions("perform"));
		set("jiali", 50);
		break;
	case 2:
		set("chat_chance_combat", 80);
		set("chat_msg_combat", get_auto_actions("perform1"));
		set("jiali", (int)query_skill("force") / 2);
		break;
	case 3:
		set("chat_chance_combat", 80);
		set("chat_msg_combat", get_auto_actions("perform2"));
		set("jiali", 1);
		break;
	default:
		set("chat_chance_combat", 80);
		set("chat_msg_combat", get_auto_actions("perform"));
		set("jiali", 50);
		return;
	}
	set("combat_mode", mode);
//	me->set("guard/status/combat_mode", mode);
}







int do_walk()
{
        string start_room;
 string name,weapon;
        object room;
        object ob;
        mapping obmap;
        int n;
        int i;
	object *inv;
        if (! environment())
                return 0;
        name = color_title[random(sizeof(color_title))]+first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))]; 
//1800
//        if (time() - query("check_time") > 3600)
      if (time() - query("check_time") > 3000 && random(100)>88 || !query_heart_beat(this_object()))
        {

       set("gender", "����");
       set("title", color_title[random(sizeof(color_title))]);
        n = 0;
	inv = all_inventory(this_object());

	for (i = 0; i < sizeof(inv); i++)
        {
                if (inv[i]->query("dynamic_quest"))
command("chat "+inv[i]->query("name")+(order[random(13)])+"���Ѿ��õ����ˡ�������!!  \n"NOR);
        }

                        message_vision("$NЦ��Ц˵�������Ѿ����֣�������ɣ����ˣ�\n"NOR, this_object());
                        destruct(this_object());
                        return 0;
        }

        n = 0;
        foreach (ob in all_inventory(environment()))
        {
                if (!ob)  continue;
                if (!ob->query("dynamic_quest"))
                        continue;
        command ("get all");
                n++;
        }

                        
        random_move();
        return 1;
}

int accept_fight(object ob)
{
				command("say " + RANK_D->query_self(this_object())
					+ "��ô������" + RANK_D->query_respect(ob)
					+ "�Ķ��֣�\n");
		  return 0;
}

int kill_ob(object ob)
{
        string start_room;
 string name,weapon;
        object room;
        mapping obmap;
        int n;
        int i;
	object *inv;
        name = color_title[random(sizeof(color_title))]+first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))]; 
		  //command("fear");
		  command("say ���ã��ұ�ʶ����!!");
if (random(3)==1)
{
command("say �Ӱ�!!");
if (random(2)==1)
{
command("go south");
command("go south");
command("go south");
command("go west");
command("go west");
command("go northup");
command("go southup");
command("go eastup");
command("go westup");
command("go northdown");
command("go southdown");
command("go eastdown");
command("go westdown");
command("go northeast");
command("go northwest");
command("go southeast");
command("go southwest");
command("go north");
command("go east");
}
else
{
command("go north");
command("go north");
command("go north");
command("go east");
command("go east");
command("go north");
command("go northup");
command("go southup");
command("go eastup");
command("go westup");
command("go northdown");
command("go southdown");
command("go eastdown");
command("go westdown");
command("go northeast");
command("go northwest");
command("go southeast");
command("go southwest");
command("go south");
command("go west");

}
}
else if ((ob->query("combat_exp") > 2500000 && random(3)==1) || random(66)==0)
{
command("say ���Ӻ���ƴ��!!");
set("qi",20000);
set("jing",20000);
set("eff_qi",20000);
set("eff_jing",20000);
set("max_qi",20000);
set("max_jing",25000);

       set("gender", "����");

	set("neili", 28000);
	set("max_neili", 28000);

	set("combat_exp", 2500000+random(250000));
	set_skill("unarmed",220);
	set_skill("force", 220);
	set_skill("dodge", 220);
	set_skill("parry", 220);
	set_skill("sword", 220);
	set_skill("staff", 220);
	set_skill("literate", 220);
	set_skill("huashan-zhangfa", 220);
	set_skill("huashan-shenfa",220);
	set_skill("huashan-jianfa", 220);
	set_skill("zixia-shengong", 220);
	set_skill("shenlong-xinfa", 220);
	set_skill("shedao-qigong", 220);

}
else if (ob->query("combat_exp") > 5000000 && random(3)==1
)
{
command("say ȥ����!!");
set("qi",38000);
set("jing",38000);
set("eff_qi",30000);
set("eff_jing",30000);
set("max_qi",30000);
set("max_jing",30000);

       set("gender", "����");

	set("neili", 38000);
	set("max_neili", 38000);

	set("combat_exp", 5000000);
       set_skill("dodge",300);
        set_skill("cuff",300);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",320);
         set_skill("feitian-yujianliu",380);
         set_skill("wuxing-dun",300);
        set_skill("shayi",300);
         set_skill("aikido",300);
         set_skill("shayi-xinfa",380);
        set_skill("shiren-jianfa",380);
        set_skill("shiren-quanfa",380);
        set_skill("force",300);
set_skill("huoxinliu-jianfa",300);

        set_skill("literate",250);
 if ((ob->query("combat_exp") > 10000000
|| ob->query_skill("jiuyin-zhengong",1) >400) && random(3)==1)
{
set("qi",42000);
set("jing",42000);
set("eff_qi",42000);
set("eff_jing",40000);
set("max_qi",40000);
set("max_jing",40000);
	set("neili", 58000);
	set("max_neili", 58000);

	set("combat_exp", 10000000);

       set_skill("dodge",400);
        set_skill("cuff",400);
        set_skill("unarmed",400);
        set_skill("parry",400);
        set_skill("blade",420);

}

}

}



string ask_job()
{     object guo,ob,obn;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
 if (!environment(guo)->query("no_fight"))
return  "������ʲô��?";
 if (environment(guo)->query("no_fight"))
{
command("say �Ӱ�!!");
if (random(2)==1)
{
random_move();
        set("chat_chance", 90);
        set("chat_msg", ({
                (: do_walk :),
                (: random_move :),
        }) );

}
else
{

random_move();
        set("chat_chance", 90);
        set("chat_msg", ({
                (: do_walk :),
                (: random_move :),
        }) );

}
}
return  "�����˶࣬����ȫ������!";
}

int hit_ob(object me, object ob, int damage)
{
string msg;
        if(random((int)me->query("combat_exp")) > random((int)ob->query("combat_exp")) || random(4)==1)   
{
             ob->add("qi",-ob->query("qi")/30);
             ob->add("eff_qi",-ob->query("eff_qi")/30);
             ob->add("jing",-ob->query("jing")/30);
             ob->add("eff_jing",-ob->query("eff_jing")/30);
         ob->apply_condition("ice_poison", 10);
        ob->apply_condition("ill_dongshang", 10);
        ob->apply_condition("ill_fashao", 10);
        ob->apply_condition("ill_kesou", 10);
        ob->apply_condition("ill_shanghan", 10);
        ob->apply_condition("ill_zhongshu", 10);        
        ob->apply_condition("xx_poison", 10);
        ob->apply_condition("cold_poison", 10);
        ob->apply_condition("flower_poison", 10);
if (random(6)==0)
ob->apply_condition("sanxiao_poison", 2);
}
           msg = HIR"$N"HIR"��Цһ��,������һ�����ҩ,"HIR"$n"HIR"���Ե�������������!!\n"NOR;
            message_vision(msg, me, ob);

}